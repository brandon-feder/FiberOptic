// Structure to represent a corinate in 2D space
struct Cord
{
    float x, y;
    
    Cord() {}

    Cord(float X, float Y)
    {
        x = X; y = Y;
    }

    // Get the distance between two cordinates
    float dist(Cord C)
    {
        return sqrt((x - C.x)*(x - C.x) + (y - C.y)*(y - C.y));
    }
};