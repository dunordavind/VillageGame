//
// Created by Petr Volkov on 18/01/2016.
//

#include "AssetManager.h"

namespace village {

    AssetManager::AssetManager() {

    }

    AssetManager::~AssetManager() {
        std::map<const assetHandlerIdType, AssetHandler *>::iterator it;
        for(it = handlers.begin(); it != handlers.end(); it++) {
            AssetHandler *handler = it->second;
            handlers.erase(it);
            delete handler;
        }
    }

    void AssetManager::registerHandler(AssetHandler *handler) {
        std::map<const assetHandlerIdType, AssetHandler *>::iterator it;

        if(handler != nullptr) {
            it = handlers.find(handler->getId());
            if(it == handlers.end()) {
                handlers.insert(std::pair<const assetHandlerIdType, AssetHandler *>(handler->getId(), handler));
            } else {
                std::cerr << " AssetManager::registerHandler( " << handler->getId() << " ): handler with this id already registered" << std::endl;
            }
        } else {
            std::cerr << " AssetManager::registerHandler( NULL ): trying to insert a NULL handler" << std::endl;
        }
    }

    bool AssetManager::loadAllAssets() {
        bool result = true;
        std::map<const assetHandlerIdType, AssetHandler *>::iterator it;

        for(it = handlers.begin(); it != handlers.end(); it++) {
            result = result && it->second->loadAllAssets();
        }
        return result;
    }

}