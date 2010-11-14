#ifndef TEXT_HPP_INCLUDED
#define TEXT_HPP_INCLUDED

/// Need easy Text? This is your class.
class Text : public virtual GameObject
{
public:
    sf::Font* Font;
    sf::String* String;

    virtual ~Text() {delete Font; delete String;};
    Text(std::string s, float size, std::string file);
    void Draw(sf::RenderWindow* App);
    void Reset();
};

#endif // TEXT_HPP_INCLUDED
