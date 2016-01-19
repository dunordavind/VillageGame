//
// Created by Petr Volkov on 18/01/2016.
//

#ifndef VILLAGEGAME_ASSETTYPES_H
#define VILLAGEGAME_ASSETTYPES_H

#include <string>
#include "Config.h"


namespace village {
    enum AssetLoadTime {
        AssetLoadNow   = 0, ///< Load the asset now
        AssetLoadLater = 1  ///< Load the asset later
    };

    /// Enumeration of AssetDropTime
    enum AssetDropTime {
        AssetDropUnspecified = 0, ///< Drop/unload time unspecified, use default AtZero
        AssetDropAtZero      = 1, ///< Drop/unload when count reaches 0
        AssetDropAtExit      = 2  ///< Drop/unload when program exits (deconstructor)
    };

    /// Enumeration of all Asset loading techniques
    enum AssetLoadStyle {
        AssetLoadFromUnknown = 0, ///< Error condition returned by GetLoadStyle
        AssetLoadFromFile    = 1, ///< Load the asset from a file
        AssetLoadFromMemory  = 2, ///< Load the asset from memory
        AssetLoadFromNetwork = 3  ///< Load the asset from the network
    };

    typedef std::string assetHandlerIdType;
    typedef Uint32 assetIdType;
}

#endif //VILLAGEGAME_ASSETTYPES_H
