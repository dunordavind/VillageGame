//
// Created by Petr Volkov on 19/01/2016.
//

#ifndef VILLAGEGAME_TASSET_H
#define VILLAGEGAME_TASSET_H

#include <AssetTypes.h>
#include "Application.h"
#include "TAssetHandler.h"

namespace village {
    template <class T>
    class TAsset {
    public:

        TAsset(const assetIdType assetId) :
        assetHandler(Application::getApp()->assetManager.getHandler<T>()),
        assetId(assetId) {

        }

        TAsset(const TAsset<T> &copy) :
        assetHandler(copy.assetHandler),
        assetId(copy.assetId) {
            asset = assetHandler.getReference(assetId);
        }

        virtual ~TAsset() {
            assetHandler.dropReference(assetId);
        }

        bool isLoaded() const {
            return assetHandler.isLoaded(assetId);
        }

        const assetIdType getId() const {
            return assetId;
        }

        void setId(const assetIdType assetID) {
            this->assetId = assetID;
            this->asset = assetHandler.getReference(assetId);
        }

        T &getAsset() {
            if(!assetHandler.isLoaded(assetId)) {
                bool loadResult = assetHandler.loadAsset(assetId);

                if(loadResult) {
                    this->asset = assetHandler.getReference(assetId);
                }
            }

            return *asset;
        }

        const std::string getFilename() {
            return assetHandler.getFilename(assetId);
        }

        void setFilename(std::string filename) {
            assetHandler.setFilename(assetId, filename);
        }

        TAsset<T> &operator=(TAsset<T> right) {
            swap(*this, right);
            assetHandler.getReference(assetId);
            return *this;
        }

        friend void swap(TAsset &first, TAsset &second) {
            using std::swap;
            swap(first.asset, second.asset);
            swap(first.assetId, second.assetId);
        }

    protected:

        TAssetHandler<T> &assetHandler;

        T *asset;

        assetIdType assetId;
    };
}

#endif //VILLAGEGAME_TASSET_H
