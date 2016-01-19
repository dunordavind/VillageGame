//
// Created by Petr Volkov on 18/01/2016.
//

#ifndef VILLAGEGAME_ASSETHANDLER_H
#define VILLAGEGAME_ASSETHANDLER_H

#include <string>
#include "AssetTypes.h"

namespace village {
    class AssetHandler {
    public:
        AssetHandler(const assetHandlerIdType assetHandlerId);

        virtual ~AssetHandler();

        const assetHandlerIdType getId() const;

        virtual void dropReference(const assetIdType) = 0;

        virtual bool isLoaded(const assetIdType) = 0;

        virtual const std::string getFilename(const assetIdType assetId) const = 0;

        virtual void setFilename(const assetIdType assetId, std::string filename) = 0;

//        virtual AssetLoadStyle getLoadStyle(const assetIdType assetId) const = 0;
//
//        virtual void setLoadStyle(const assetIdType assetId, AssetLoadStyle loadStyle) = 0;

//        virtual AssetLoadTime getLoadTime(const assetIdType assetId) const = 0;
//
//        virtual void setLoadTime(const assetIdType assetId, AssetLoadTime loadTime) = 0;

        virtual bool loadAsset(const assetIdType assetId) = 0;

        virtual bool loadAllAssets() = 0;
    protected:
    private:
        const assetHandlerIdType assetHandlerId;

        AssetHandler(const AssetHandler &);

        AssetHandler& operator=(const AssetHandler &);
    };
}


#endif //VILLAGEGAME_ASSETHANDLER_H
