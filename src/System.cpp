//
// Created by Petr Volkov on 17/01/2016.
//

#include "System.h"
#include "Entity.h"

namespace village {


    System::System(const systemIdType systemId, Application &application) :
    systemId(systemId),
    application(application) {

    }

    const systemIdType System::getSystemId() const {
        return systemId;
    }

    System::~System() {
        dropAllEntities();
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

    bool System::hasEntity(const entityIdType entityId) const {
        bool result = false;

        std::map<const Uint32, std::deque<Entity *>>::const_iterator it;
        it = entities.begin();

        while(it != entities.end() && !result) {
            std::deque<Entity *>::const_iterator it2 = it->second.begin();
            while(it2 != it->second.end()) {
                if(entityId == (*it2)->getEntityId()) {
                    result = true;
                    break;
                }

                it2++;
            }
            it++;
        }

        return result;
    }

    void System::dropEntity(const entityIdType entityId) {
        bool result = false;

        std::map<const Uint32, std::deque<Entity *>>::iterator it;
        it = entities.begin();

        while(it != entities.end() && !result) {
            std::deque<Entity *>::iterator it2 = it->second.begin();
            while(it2 != it->second.end()) {
                if(entityId == (*it2)->getEntityId()) {
                    it2 = eraseEntity(it2);
                    result = true;
                    break;
                }

                it2++;
            }
            it++;
        }
    }

    std::deque<Entity *>::iterator System::eraseEntity(std::deque<Entity *>::iterator entityIterator) {
        std::deque<Entity *>::iterator result;
        Entity *targetEntity = (*entityIterator);
        result = entities[targetEntity->getZOrder()].erase(entityIterator);
        cleanup(targetEntity);

        if(targetEntity->hasSystem(getSystemId())) {
            targetEntity->dropSystem(getSystemId());
        }
        return result;
    }

    void System::dropAllEntities() {
        std::map<const Uint32, std::deque<Entity *>>::iterator it;
        it = entities.begin();

        while(it != entities.end()) {
            std::deque<Entity *>::iterator it2 = it->second.begin();
            while(it2 != it->second.end()) {
                it2 = eraseEntity(it2);
            }
            it++;
        }
    }
}