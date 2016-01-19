//
// Created by Petr Volkov on 18/01/2016.
//

#ifndef VILLAGEGAME_ASSETMANAGER_H
#define VILLAGEGAME_ASSETMANAGER_H

#include <map>
#include <iostream>
#include <typeinfo>
#include <templates/TAssetHandler.h>
#include "AssetTypes.h"
#include "AssetHandler.h"

namespace village {
    class AssetManager {
    public:

        AssetManager();

        virtual ~AssetManager();

        void registerHandler(AssetHandler *handler);

        bool loadAllAssets();

        template<typename T>
        TAssetHandler<T> &getHandler() const {
            TAssetHandler<T> *result = nullptr;

            std::map<const assetHandlerIdType, AssetHandler *>::const_iterator it = handlers.find(typeid(T).name());

            if (it != handlers.end()) {
                result = static_cast<TAssetHandler<T> *>(it->second);
            }

            if(result == nullptr) {
                //change to logger after logger implemeneted
                std::cerr << " AssetManager::getHandler( " << typeid(T).name() << " ) not found" << std::endl;
            }

            return *result;
        }


    private:
        std::map<const assetHandlerIdType, AssetHandler *> handlers;
        AssetManager(const AssetManager&);
        AssetManager& operator=(const AssetManager&);
    };
}
#endif //VILLAGEGAME_ASSETMANAGER_H
