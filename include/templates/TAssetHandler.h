//
// Created by Petr Volkov on 18/01/2016.
//

#ifndef VILLAGEGAME_TASSETHANDLER_H
#define VILLAGEGAME_TASSETHANDLER_H

#include <AssetHandler.h>
#include <map>
#include <iostream>

namespace village {
    template <typename T>
    class TAssetHandler : public AssetHandler {
    public:
        TAssetHandler() :
        AssetHandler(typeid(T).name()) {

        }

        virtual ~TAssetHandler() {
            // delete all assets
            typename std::map<const assetIdType, assetDataType>::iterator it;
            for(it = assets.begin(); it != assets.end(); it++) {
                it->second.count--;
                if(it->second.count != 0) {
                    //this is an error - someone is still referencing this asset
                    std::cerr << "~TAssetHandler: attempt to deconstruct handler " << getId() << " but assetId " << it->first << " not found " << std::endl;
                }
                const assetIdType assetId = it->first;
                T *asset = it->second.asset;

                assets.erase(it);
                releaseAsset(assetId, asset);
                asset = nullptr;
            }
        }

        //asset is always dropped when count is 0 for now (for fun and profit)
        virtual void dropReference(const assetIdType assetId) {
            typename std::map<const assetIdType, assetDataType>::iterator it = assets.find(assetId);

            if(it != assets.end()) {
                it->second.count--;
                if(it->second.count == 0) {
                    T *asset = it->second.asset;
                    assets.erase(it);
                    releaseAsset(assetId, asset); // just delete
                }
            } else {
                // log an error - implement after logger
                std::cerr << "dropReference: attempt to drop a reference " << getId() << " but assetId " << assetId << " not found " << std::endl;
            }

        }

        T *getReference(const assetIdType assetId) {
            T *result = nullptr;
            typename std::map<const assetIdType, assetDataType>::iterator it = assets.find(assetId);

            if(it != assets.end()) {
                it->second.count++;
                result = it->second.asset;
            } else {
                result = acquireAsset(assetId);
                if(result != nullptr) {
                    assetDataType assetData;

                    assetData.asset = result;
                    assetData.count = 1;
                    assetData.loaded = false;
                    assetData.filename = assetId;

                    assets.insert(std::pair<const assetIdType, assetDataType>(assetId, assetData));
                    loadAsset(assetId);
                }

            }

            if(result == nullptr) {
                result = &dummyAsset;
            }

            return result;
        }

        virtual bool loadAsset(const assetIdType assetId) {
            bool result = false;

            typename std::map<const assetIdType, assetDataType>::iterator it = assets.find(assetId);

            if(it != assets.end()) {
                if(!it->second.loaded) {
                    //implement load styles - not implemented, only load from file
                    loadFromFile(assetId, *(it->second.asset));
                }
            }
            result = it->second.loaded;
            return result;
        }

        virtual bool loadAllAssets() {
            bool result = true;

            typename std::map<const assetIdType, assetDataType>::iterator it = assets.begin();
            while(it != assets.end()) {
                if(!it->second.loaded) {
                    it->second.loaded = loadFromFile(it->first, *(it->second.asset));
                }
                *it++;
                result = result && it->second.loaded;
            }
            return result;
        }

        //pure virtual methods
        virtual bool loadFromFile(const assetIdType assetId, T &asset) = 0;
    protected:
        virtual T *acquireAsset(const assetIdType assetId) {
            return new T();
        }

        //refactor
        virtual void releaseAsset(const assetIdType assetId, T *asset) {
            delete asset;
        }

    private:
        struct assetDataType {
            T *asset;
            Uint32 count;
            bool loaded;
            std::string filename;
        };
        std::map<const assetIdType, assetDataType> assets;
        T dummyAsset; // Dummy asset that will be returned if an asset can't be Acquired
    };
}

#endif //VILLAGEGAME_TASSETHANDLER_H
