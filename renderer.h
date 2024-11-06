SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

//Texture wrapper class
class LTexture
{
public:
  //Initializes variables
  LTexture();

  //Deallocates memory
  ~LTexture();

  //Loads image at specified path
  bool loadFromFile( std::string path );

  bool loadFromRenderedText( std::string textureText, SDL_Color textColor, int wrapBoundary, TTF_Font* gFont);

  //Deallocates texture
  void free();

  //Set color modulation
  void setColor( Uint8 red, Uint8 green, Uint8 blue );

  //Set blending
  void setBlendMode( SDL_BlendMode blending );

  //Set alpha modulation
  void setAlpha( Uint8 alpha );
		
  //Renders texture at given point
  void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
  SDL_Rect mBox;

  //Gets image dimensions
  int getWidth();
  int getHeight();

  SDL_Rect getBox();
  
  //The actual hardware texture
  SDL_Texture* mTexture;
public:
  //Image dimensions
  float mWidth;
  float mHeight;

};
