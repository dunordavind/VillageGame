//
// Created by Petr Volkov on 17/01/2016.
//

#include "System.h"
#include "Entity.h"

namespace village {


    System::System(const systemIdType systemId, Application &application) :
    id(systemId),
    application(application) {

    }

    const systemIdType System::getId() const {
        return id;
    }

    System::~System() {
    //    dropAllEntities();
    }

    const entityIdType System::addEntity(Entity *entity) {
        entityIdType result = 0;

        if(entity != NULL) {
            bool added = false;
            std::deque<Entity *>::iterator it;
            Uint32 zOrder = entity->getZOrder();

            //find if there already exists this entity in the same z-order
            it = std::find(entities[zOrder].begin(), entities[zOrder].end(), entity);

            if(it == entities[zOrder].end()) {
                entities[entity->getZOrder()].push_back(entity);

                addProperties(entity);
                entity->addSystem(this);
                init(entity);
            }

        } else {
            throw "Null entity pointer provided"; //change to log class
        }
        return result;
    }
}