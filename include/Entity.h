//
// Created by Petr Volkov on 17/01/2016.
//

#ifndef VILLAGEGAME_ENTITY_H
#define VILLAGEGAME_ENTITY_H

#include <map>
#include "EntityTypes.h"

namespace village {
    class System;

    class Entity {
    public:
        Entity(Uint32 zOrder = 0);
        virtual ~Entity();

//        const entityIdType getEntityId() const;
        static entityIdType nextAvailableId();
        const Uint32 getZOrder() const;
        void setZOrder(const Uint32 order);

        virtual void destroy() = 0;

        void addSystem(System *system);
        bool hasSystem(const systemIdType systemId) const;
        void dropSystem(const systemIdType systemId);
    protected:
        std::map<const systemIdType, System *> systems;
        void dropAllSystems();
    private:
        entityIdType entityId;
        static entityIdType nextId;
        Uint32 zOrder;
    };
}


#endif //VILLAGEGAME_ENTITY_H
