#pragma once
class GameBehaviour
{
    public:
        virtual ~GameBehaviour() = default;

        virtual void BeginPlay() = 0;
        virtual void Update() = 0;
};