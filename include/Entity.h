//
// Created by Petr Volkov on 17/01/2016.
//

#ifndef VILLAGEGAME_ENTITY_H
#define VILLAGEGAME_ENTITY_H

#include "EntityTypes.h"
#include "System.h"

namespace village {
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
        bool hasSystem(const systemIdType systemID) const;
        void dropSystem(const systemIdType systemID);
    protected:
        void dropAllSystems();

    private:
        entityIdType entityId;
        static entityIdType nextId;
        Uint32 zOrder;
    };
}


#endif //VILLAGEGAME_ENTITY_H
