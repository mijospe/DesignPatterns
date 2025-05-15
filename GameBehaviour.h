#pragma once
class GameBehaviour
{
    public:
        virtual ~GameBehaviour() = default;

        // Interface Functions
        virtual void BeginPlay() = 0;
        virtual void Update() = 0;
};