#ifndef ANIOBJECT_HPP_INCLUDED
#define ANIOBJECT_HPP_INCLUDED

namespace Ignatus{

/// Static images are boring, spice things up with easy animated images!
class AniObject : public virtual GameObject
{
public:
    AniSprite* AS;

    AniObject(std::string file, Point<float> xy, Point<int> dim, int frame_rate, bool endOnEnd);
    virtual ~AniObject();

    virtual void UpdateMagic();
};
}
#endif // ANIOBJECT_HPP_INCLUDED
