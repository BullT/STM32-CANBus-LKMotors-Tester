#ifndef MODEL_HPP
#define MODEL_HPP

#include <cstdint>

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void sendData(uint8_t *data);
protected:
    ModelListener* modelListener;
    uint8_t receptionBuffer[8];
    //uint8_t receptionBuffer[8] = {0xA8, 0x00, 0xFF, 0x0F, 0xFF, 0x0F, 0x00, 0x00};
};

#endif // MODEL_HPP
