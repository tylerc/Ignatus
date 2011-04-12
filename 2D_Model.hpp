#ifndef TwoD_MODEL_HPP
#define TwoD_MODEL_HPP

namespace Ignatus{

/// Allows you to display a two dimensional object with multiple image stripes.
/**
contrasted to AniObject, which only has one image strip, this can have many orginized in a vector.
Easy to use and set witohut the need of multiple objects.
*/
class TwoD_Model:public virtual GameObject{
public:
    /// This struct handles animation frames.
    /**
    has a name to be refered to, an AniSprite which is the actual image strip.
    */
    struct Animation{
        std::string Name; //!< The name of the frame to refer to.
        AniSprite* Frames; //!< The raw AniSprite of the frame.

        /// Constructor for a Animation frame.
        /**
        Creates an AniSprite and a name, defaults to Stand.
        */
        Animation(std::string file,Pointi dim,int fps,bool eoe,std::string name="Stand");
    };
    std::string CurFrame; //!< The name of the current Animation frame.

    /// This creates the Stand Animation frame from the given parameters.
    /**
    This is the default image to loop over.
    */
    TwoD_Model(std::string img,Pointi dim,float fps,bool eoe=false);
    /// Removes the Object.
    /**
    Commonly overwritten to provide death behavour.
    */
    virtual ~TwoD_Model();
    /// Do not override unless you know what your're doing.
    /**
    This handels the frames each step.
    */
    virtual void UpdateMagic();
    /// Returns the current Animation frame AniSprite.
    /**
    Given a name will return the animated image strip.
    */
    AniSprite* GetFrame(std::string name="Stand");
    /// Returns the number the Animation frame resides in the Animations vector.
    /**
    You should never need this, but it's here.
    */
    int GetFrameID(std::string name="Stand");
    /// Allows you to change the displayed Animation strip.
    /**
    Given a name sets the frame to draw, defaults to Stand.
    */
    void SetFrame(std::string name="Stand");
    /// Adds an image frame to the TwoD_Model.
    /**
    Given the parameters, adds a AniSprite and name to form a new Aniamtion strip to display.
    Call SetFrame(name) to display your added frame.
    */
    void AddFrame(std::string img,std::string name,bool eoe=false);
private:
    Pointi Dim; //!< height and width of the TwoD_Model, all Animation strips must have the same frame dimensions.
    float FPS; //!< Frames per second to display the AniSprites
    std::vector<Animation> Animations; //!< Vecgor containing all the TwoD_Model's Animation objects.
};

}

#endif // TwoD_MODEL_HPP
