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
//        dropAllSystems();
    }

    const Uint32 Entity::getZOrder() const {
        return zOrder;
    }

    void Entity::setZOrder(const Uint32 zOrder) {
        this->zOrder = zOrder;
    }


//    void Entity::dropAllSystems() {
//        //to be implemented after system class
//    }
//
//    void Entity::addSystem(System *system) {
//        //to be implemented after system class
//    }


    void Entity::addSystem(System *system) {
        if(systems.find(system->getId()) == systems.end()) {
            systems[system->getId()] = system;
        }
    }

    bool Entity::hasSystem(const systemIdType systemId) const {
        bool result = false;
        if(systems.find(systemId) != systems.end()) {
            result = true;
        }
        return result;
    }
}