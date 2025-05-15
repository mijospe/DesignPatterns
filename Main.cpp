#include <iostream>
#include <SFML/Graphics.hpp>
#include "EnemyFactory.h"

// Show the list of commands
void CommandList()
{
    std::cout << "List of Commands:" << std::endl <<
        "Help                   - Shows the Command List" << std::endl <<
        "Quit                   - Quit the Application" << std::endl <<
        "Spawn [ENEMY]          - Spawns an enemy" << std::endl <<
        "Destroy [ENEMY]        - Destroys an enemy" << std::endl <<
        "Clear                  - Clears the console" << std::endl <<
        "---------------------------------------------------------------" << std::endl <<
        "   Enemy Types:" << std::endl <<
        "       - Freddy" << std::endl <<
        "       - Bonnie" << std::endl <<
        "       - Chica" << std::endl <<
        "       - Foxy" << std::endl <<
        "       - Golden Freddy" << std::endl
        ;
}

int main()
{
    // The input of the user
    std::string input;

    EnemyFactory factory{};

    std::vector<std::unique_ptr<Entity>> entitiesInLevel;

    CommandList();

    // Event Tick (Runs every frame)
    while (true) {
        // Give the prompt to execute a command
        std::cout << "Execute Command: ";
        std::getline(std::cin, input);

        std::cout << std::endl;

        // Check executed Command
        // Spawn entity
        if (input.find("Spawn") != std::string::npos)
        {
            std::unique_ptr<Entity> spawnedEntity = factory.SpawnEnemy(input);
            if (spawnedEntity)
            {
                std::cout << ">> " << spawnedEntity->name;
                entitiesInLevel.push_back(std::move(spawnedEntity));
            }
            else std::cout << ">> Error: Entity could not be spawned, Pool is empty, Destroy this entity to be able to spawn another one";
        }
        // Destroy entity
        else if (input.find("Destroy") != std::string::npos)
        {
            if (entitiesInLevel.size() > 0)
            {
                for (auto it = entitiesInLevel.begin(); it != entitiesInLevel.end();)
                {
                    if ("Destroy " + (*it)->name == input)
                    {
                        factory.DestroyEntity(std::move(*it));
                        it = entitiesInLevel.erase(it);
                    }
                    else
                    {
                        if (it == entitiesInLevel.end())
                        {
                            std::cout << ">> Error: Could not destroy Entity, make sure to spawn one or fill in the correct name";
                        }
                        ++it;
                    }
                }
            }
            else
            {
                std::cout << ">> Error: No entities found";
            }
        }
        // Show commands
        else if (input == "Help")
        {
            CommandList();
        }
        // Clear the chat
        else if (input == "Clear")
        {
            system("cls");
            CommandList();
        }
        // Quit program
        else if (input == "Quit")
        {
            return 0;
        }
        // Invalid command
        else
        {
            std::cout << ">> ERROR: Command not recognized\n";
        }

        // Add some spacing
        std::cout << std::endl << std::endl;

        // Update all Entities
        for (int i = 0; i < entitiesInLevel.size(); i++)
        {
            entitiesInLevel[i]->Update();
        }
    }

	return 0;
}