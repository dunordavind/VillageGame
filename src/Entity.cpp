//
// Created by Petr Volkov on 17/01/2016.
//

#include "Entity.h"
#include "System.h"

namespace village {

    entityIdType Entity::nextId = 0;

    entityIdType Entity::nextAvailableId() {
        return ++nextId;
    }

    Entity::Entity(Uint32 zOrder) :
    entityId(nextAvailableId()),
    zOrder(zOrder) {

    }

    Entity::~Entity() {
        dropAllSystems();
    }

    const Uint32 Entity::getZOrder() const {
        return zOrder;
    }

    void Entity::setZOrder(const Uint32 zOrder) {
        this->zOrder = zOrder;
    }


    void Entity::dropAllSystems() {
        std::map<const systemIdType, System *>::iterator it = systems.begin();
        while(it != systems.end()) {
            eraseSystem(it);
            it++;
        }
        systems.clear();
    }

    void Entity::addSystem(System *system) {
        if(systems.find(system->getSystemId()) == systems.end()) {
            systems[system->getSystemId()] = system;
        }
    }

    bool Entity::hasSystem(const systemIdType systemId) const {
        bool result = false;
        if(systems.find(systemId) != systems.end()) {
            result = true;
        }
        return result;
    }

    void Entity::dropSystem(const systemIdType systemId) {
        //loop throw each registered system, compare id and drop
        std::map<const systemIdType, System *>::iterator it;

        it = systems.find(systemId);
        if(it != systems.end()) {
            eraseSystem(it);
        } else {
            //add logging
        }
    }

    void Entity::eraseSystem(std::map<const systemIdType, System *>::iterator it) {
        System *system = it->second;
        systems.erase(it);
        systemIdType currentEntityId = getEntityId();

        if(system->hasEntity(currentEntityId)) {
            system->dropEntity(currentEntityId);
        }
    }

    const entityIdType Entity::getEntityId() const {
        return entityId;
    }
}