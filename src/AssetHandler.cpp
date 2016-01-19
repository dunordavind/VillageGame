//
// Created by Petr Volkov on 18/01/2016.
//

#include "AssetHandler.h"

namespace village {

    AssetHandler::AssetHandler(const assetHandlerIdType assetHandlerId) :
    assetHandlerId(assetHandlerId) {

    }

    AssetHandler::~AssetHandler() {

    }

    const assetHandlerIdType AssetHandler::getId() const {
        return assetHandlerId;
    }
}