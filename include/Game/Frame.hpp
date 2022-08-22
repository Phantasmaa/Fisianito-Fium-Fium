#pragma once

class Frame
{
public:
    // Variables
    int leftX;                        // coordenada x del Spreadsheet (Frame a utilizar)
    class Frame *nextFrame = nullptr; // punteor al siguiente
};