//
// Created by Petr Volkov on 17/01/2016.
//

#ifndef VILLAGEGAME_SYSTEM_H
#define VILLAGEGAME_SYSTEM_H


#include <deque>
#include <map>
#include <SFML/Window/Event.hpp>
#include "Application.h"
#include "EntityTypes.h"

namespace village {
    class Entity;

    class System {
    public:
        System(const systemIdType systemId, Application &application);
        virtual ~System();

        const systemIdType getId() const;
        const entityIdType addEntity(Entity *entity);
        bool hasEntity(const entityIdType entityId) const;
        void dropEntity(const entityIdType entityId);
        void dropAllEntities();

        virtual void handleEvents(sf::Event event) = 0;
        virtual void addProperties(Entity *entity) = 0;
        virtual void update() = 0;
        virtual void draw() = 0;

    protected:
        std::map<const Uint32, std::deque<Entity *>> entities; //Uint32 key is z-order
        Application &application;

        virtual void init(Entity *entity) = 0;
        virtual void cleanup(Entity *entity) = 0;
    private:
        const systemIdType id;
        std::deque<Entity *>::iterator eraseEntity(std::deque<Entity *>::iterator entityIterator);
    };
}


#endif //VILLAGEGAME_SYSTEM_H
