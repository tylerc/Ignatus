#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED
/// Point is for using velocities and angle movement. Also used for coords.
/**
This basicly as two float values; x and y. This allows you to return two floats rather than only one value.
Also has a few funtions for converting velocity to angles and speed.
Supports basic math, like eadding, also allows to check is Points have the same value.
*/
class Point{
public:
    float x; //!< This is the first of the the pair of floats, called x because of standard coords.
    float y; //!< This is the second of the the pair of floats, called y because of standard coords.
    /// The Points's constuctor.
    /**
    This creates a Point with a given x and y initialized in it.
    */
    Point(float x,float y);
    /// The Points's default constuctor.
    /**
    This creates a Point. However the x and y has not been set to anything yet.
    */
    Point();
    /// The Points's deconstuctor.
    /**
    Simply removes the Point from existance.
    */
    ~Point();
    /// Take's two floats and turns them into a Point.
    /**
    When given two floats, the first one is considered velocity and the second one is the angle. It then
    converts them into the horizontal and virtical vector componants, vx and vy. Returns them as a Point.
    */
    static Point get_vel(float speed,float angle);
    /// Take's a Point and converts it.
    /**
    Converts a given Point (assuming that x is speed and y and angle) and returns them as vx and vy, in a new Point.
    */
    static Point get_vel(Point p);
    /// The inverse of get_vel.
    /**
    Take's a vx and vy float and returns it as a Point with the x being a speed and the y as an angle.
    */
    static Point get_ang(float vx,float vy);
    /// The inverse of get_vel
    /**
    Takes a Point and returns a Point converted to vx and vy.
    */
    static Point get_ang(Point p);
    /// Allows you to add Points
    /**
    Adds the x and y of two Points, just like adding integers.
    */
    Point operator+(Point param);
    /// Allows you to subtract Points
    /**
    Subtracts the x and y of two Points, just like subtracting integers.
    */
    Point operator-(Point param);
    /// Allows you to multiply Points
    /**
    Multiplies the x and y of two Points, just like multiplying integers.
    */
    Point operator*(Point param);
    /// Allows you to divides Points
    /**
    Divides the x and y of two Points, just like dividing integers.
    */
    Point operator/(Point param);
    /// Allows you to check is two Points are equal
    /**
    Compares the x and y of two Points, to see if the Points are equal.
    */
    bool operator==(Point param);
};

#endif // POINT_HPP_INCLUDED
