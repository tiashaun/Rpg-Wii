//header for files and stuffz
bool HasColided(SDL_Rect,SDL_Rect);
/*
0 - grass
1 - Border
2 - Dirt
3 - water
4 - left top 
5 - left
6 - left bottom
7 - right top
8 - right
9 - right bottom
*/
int map[50][50] = 
{
4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
5,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
5,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,1,1,1,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,2,2,0,
5,0,0,0,0,2,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,9,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,
5,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,
5,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,
5,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,9,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,
5,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,8,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,
5,0,0,0,0,2,2,2,2,2,2,2,2,0,0,1,8,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,
5,0,0,0,0,2,0,0,0,0,0,0,0,0,0,8,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,2,0,0,0,0,0,0,0,0,0,8,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,2,0,0,0,0,0,0,0,0,0,8,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,2,0,0,0,0,0,0,0,0,0,8,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
6,1,1,1,0,2,0,0,0,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,2,0,0,0,0,0,0,8,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,2,0,0,0,0,0,0,8,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,2,0,0,0,0,0,0,8,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,2,0,0,0,0,0,0,8,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,0,0,0,0,0,0,0,8,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,4,1,1,1,1,1,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,5,1,3,3,3,3,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
5,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,5,1,1,3,3,3,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
6,1,1,0,0,0,1,1,0,0,0,0,8,0,0,0,0,5,1,3,3,3,3,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,1,0,0,0,1,1,0,0,0,0,8,0,0,0,0,6,1,1,1,1,1,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,1,0,0,0,1,1,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,1,0,0,0,1,1,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,1,0,0,0,1,1,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,1,0,0,0,1,1,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,1,0,0,0,1,1,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,1,0,0,0,1,1,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,1,1,1,1,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
int LevelMaxX =1600;
int LevelMaxY =1600;
int GameMode;
int Ticks;
enum faceing
{
UP,
DOWN,
LEFT,
RIGHT
}faceing;

SDL_Color Selected = {0xFF,0x00,0x00};
SDL_Color NotSelected = {0xFF,0xFF,0xFF};
TTF_Font *font = NULL;
SDL_Rect Tiles[50][50];
SDL_Rect PlayerRect;

SDL_Rect AiRect[10];
char AiNameTable[10];
const char MenuItemsTable[4];
SDL_Rect AiCol[10];


SDL_Rect TestClip[10];
SDL_Rect Camera;

int MenuItemSelected = 0;
int MenuMax = 4;

SDL_Rect SabrinaClipUp[2];
SDL_Rect SabrinaClipDown[2];
SDL_Rect SabrinaClipLeft[2];
SDL_Rect SabrinaClipRight[2];



SDL_Surface * screen = NULL;
SDL_Surface * test = NULL;
SDL_Surface * sabrina = NULL;
SDL_Surface * text = NULL;
SDL_Surface * menu = NULL;

u32 held;
u32 rel;
u32 pressed;
int PlayerXvel;
int PlayerYvel;
int PlayerFrame = 0;

void init()
{

char AiNameTable[10] = {'Programmer Test','Bobby Ray','Billy Joe','Debug Output','sex','dude','epic','C++','SDL','love','abc?'};
char MenuItemsTable[4] = {'Inventory','Stats','Save','Abilities','Help'};

PlayerRect.x = 50;
PlayerRect.y = 120;
PlayerRect.w = 30;
PlayerRect.h = 30;


TestClip[0].x = 0;
TestClip[0].y = 0;
TestClip[0].w = 32;
TestClip[0].h = 32;

TestClip[1].x = 0;
TestClip[1].y = 32;
TestClip[1].w = 32;
TestClip[1].h = 32;

TestClip[2].x = 0;
TestClip[2].y = 64;
TestClip[2].w = 32;
TestClip[2].h = 32;

TestClip[3].x = 0;
TestClip[3].y = 96;
TestClip[3].w = 32;
TestClip[3].h = 32;


TestClip[4].x = 0;
TestClip[4].y = 128;
TestClip[4].w = 32;
TestClip[4].h = 32;


TestClip[5].x = 0;
TestClip[5].y = 160;
TestClip[5].w = 32;
TestClip[5].h = 32;


TestClip[6].x = 0;
TestClip[6].y = 192;
TestClip[6].w = 32;
TestClip[6].h = 32;

TestClip[7].x = 0;
TestClip[7].y = 224;
TestClip[7].w = 32;
TestClip[7].h = 32;

TestClip[8].x = 0;
TestClip[8].y = 256;
TestClip[8].w = 32;
TestClip[8].h = 32;

TestClip[9].x = 0;
TestClip[9].y = 288;
TestClip[9].w = 32;
TestClip[9].h = 32;



Camera.x = 0;
Camera.y = 0;
Camera.w = 640;
Camera.h = 480;

	//Down
	SabrinaClipDown[0].x = 0;
	SabrinaClipDown[0].y = 0;
	SabrinaClipDown[0].w = 32;
	SabrinaClipDown[0].h = 32;
	
	SabrinaClipDown[1].x = 0;
	SabrinaClipDown[1].y = 32;
	SabrinaClipDown[1].w = 32;
	SabrinaClipDown[1].h = 32;
	
	//Up
	SabrinaClipUp[0].x = 32;
	SabrinaClipUp[0].y = 0;
	SabrinaClipUp[0].w = 32;
	SabrinaClipUp[0].h = 32;
	
	SabrinaClipUp[1].x = 32;
	SabrinaClipUp[1].y = 32;
	SabrinaClipUp[1].w = 32;
	SabrinaClipUp[1].h = 32;
	
	//Right
	SabrinaClipRight[0].x = 64;
	SabrinaClipRight[0].y = 0;
	SabrinaClipRight[0].w = 32;
	SabrinaClipRight[0].h = 32;
	
	SabrinaClipRight[1].x = 64;
	SabrinaClipRight[1].y = 32;
	SabrinaClipRight[1].w = 32;
	SabrinaClipRight[1].h = 32;
	
	//Left
	SabrinaClipLeft[0].x = 96;
	SabrinaClipLeft[0].y = 0;
	SabrinaClipLeft[0].w = 32;
	SabrinaClipLeft[0].h = 32;
	
	SabrinaClipLeft[1].x = 96;
	SabrinaClipLeft[1].y = 32;
	SabrinaClipLeft[1].w = 32;
	SabrinaClipLeft[1].h = 32;
  
    if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 )
    {
        fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError() );
		SDL_Delay( 5000 );
        exit(EXIT_FAILURE);
    }
 
    
    WPAD_Init();
	TTF_Init();
    SetupTextOverlay();
    atexit(SDL_Quit);
    SDL_ShowCursor(SDL_DISABLE);
	
    test = SDL_LoadBMP("sd:/apps/SDL/test.bmp");
	sabrina = SDL_LoadBMP("sd:/apps/SDL/sabrina.bmp");
	menu = SDL_LoadBMP("sd:/apps/SDL/menu.bmp");
	
	Uint32 colorkey = SDL_MapRGB(test->format, 0, 0, 0 ); //black == transparent
	Uint32 cc		= SDL_MapRGB(sabrina->format,0xFF,0xFF,0xFF);
	SDL_SetColorKey(test, SDL_SRCCOLORKEY, colorkey );
	SDL_SetColorKey(sabrina,SDL_SRCCOLORKEY,cc);
	
    screen = SDL_SetVideoMode(640, 480, 16, SDL_DOUBLEBUF);
    if ( !screen )
    {
        fprintf(stderr, "Unable to set video: %s\n", SDL_GetError());
		SDL_Delay( 5000 );
        exit(EXIT_FAILURE);
    }
}
 

void apply_surface(int x,int y,SDL_Surface* source,SDL_Surface* destination,SDL_Rect* clip) 
{ 
SDL_Rect offset; 
offset.x = x; 
offset.y = y; 
SDL_BlitSurface( source, clip, destination, &offset ); 
} 
 
void cleanup()
{
     SDL_Quit();
     exit(EXIT_SUCCESS);
}

void RenderMap(int m[50][50])
{
int a,b;
for(a=0;a < 50;a++)
{
	for(b=0;b < 50;b++)
	{
		Tiles[a][b].x = b * 32;
		Tiles[a][b].y = a * 32;
		Tiles[a][b].w = 32;
		Tiles[a][b].h = 32;
		
		if(HasColided(Camera,Tiles[a][b]))
		{
		
		if(m[a][b] == 1)
		{
		apply_surface(Tiles[a][b].x -Camera.x,Tiles[a][b].y - Camera.y,test,screen,&TestClip[0]);
		}
		
		else if(m[a][b] == 0)
		{
		apply_surface(Tiles[a][b].x - Camera.x,Tiles[a][b].y - Camera.y,test,screen,&TestClip[1]);
		}
		
		else if(m[a][b] == 2)
		{
		apply_surface(Tiles[a][b].x - Camera.x,Tiles[a][b].y - Camera.y,test,screen,&TestClip[2]);
		}
		
		else if(m[a][b] == 3)
		{
		apply_surface(Tiles[a][b].x - Camera.x,Tiles[a][b].y - Camera.y,test,screen,&TestClip[3]);
		}
		
		else if(m[a][b] == 4)
		{
		apply_surface(Tiles[a][b].x - Camera.x,Tiles[a][b].y - Camera.y,test,screen,&TestClip[4]);
		}
		
		else if(m[a][b] == 5)
		{
		apply_surface(Tiles[a][b].x - Camera.x,Tiles[a][b].y - Camera.y,test,screen,&TestClip[5]);
		}
		
		else if(m[a][b] == 6)
		{
		apply_surface(Tiles[a][b].x - Camera.x,Tiles[a][b].y - Camera.y,test,screen,&TestClip[6]);
		}
		
		else if(m[a][b] == 7)
		{
		apply_surface(Tiles[a][b].x - Camera.x,Tiles[a][b].y - Camera.y,test,screen,&TestClip[7]);
		}
		
		else if(m[a][b] == 8)
		{
		apply_surface(Tiles[a][b].x - Camera.x,Tiles[a][b].y - Camera.y,test,screen,&TestClip[8]);
		}
		
		else if(m[a][b] == 9)
		{
		apply_surface(Tiles[a][b].x - Camera.x,Tiles[a][b].y - Camera.y,test,screen,&TestClip[9]);
		}
		
		}
		
	}
}
}

/*
0 - grass O
1 - Border X
2 - Dirt O
3 - water X
4 - left top X
5 - left X
6 - left bottom X
7 - right top X
8 - right X
9 - right bottom X
*/
bool CheckTileCol(int m[50][50])
{
int a,b;
for(a=0;a < 50;a++)
{
	for(b=0;b < 50;b++)
	{
	
	if(m[a][b] == 1 || m[a][b] == 3 || m[a][b] == 4 || m[a][b] == 5 || m[a][b] == 6 || m[a][b] == 7 || m[a][b] == 8 || m[a][b] == 9)
	{
	
	if(HasColided(PlayerRect,Tiles[a][b]))
	{
	return true;
	}
	
	}

	
	}
}
return false;
}

bool HasAiCol()
{
int c;

for(c=0;c < 10;c++)
{
if(HasColided(AiRect[c],AiCol[c]))
{
return true;
}

}
return false;
}



bool HasColided(SDL_Rect A,SDL_Rect B)
{
//The sides of the rectangles 
int leftA, leftB; 
int rightA, rightB; 
int topA, topB; 
int bottomA, bottomB; 

//Calculate the sides of rect A 
leftA = A.x; 
rightA = A.x + A.w; 
topA = A.y; 
bottomA = A.y + A.h; 

//Calculate the sides of rect B 
leftB = B.x; 
rightB = B.x + B.w; 
topB = B.y; 
bottomB = B.y + B.h; 

if( bottomA <= topB ) 
{ 
return false; 
} 

if( topA >= bottomB ) 
{ 
return false; 
} 

if( rightA <= leftB ) 
{ 
return false; 
} 

if( leftA >= rightB ) 
{ 
return false; 
} 
//If none of the sides from A are outside B 
return true; 

}

void DoInput()
{

if(pressed & WPAD_BUTTON_UP)
{
PlayerYvel -= 16;
}

else if(rel & WPAD_BUTTON_UP)
{
PlayerYvel += 16;
}

if(pressed & WPAD_BUTTON_DOWN)
{
PlayerYvel += 16;
}

else if(rel & WPAD_BUTTON_DOWN)
{
PlayerYvel -= 16;
}

if(pressed & WPAD_BUTTON_LEFT)
{
PlayerXvel -= 16;
}

else if(rel &WPAD_BUTTON_LEFT)
{
PlayerXvel += 16;
}

if(pressed & WPAD_BUTTON_RIGHT)
{
PlayerXvel += 16;
}

else if(rel & WPAD_BUTTON_RIGHT)
{
PlayerXvel -= 16;
}

if(held & WPAD_BUTTON_A)
{
if(HasAiCol() == true)
{
DrawTextOverlay(25,25,"HitTest 1",NotSelected);
}
else
{
DrawTextOverlay(25,25,"HitTest 0",NotSelected);
}

}

else if(pressed & WPAD_BUTTON_PLUS)
{
GameMode = 2;
return;
if(GameMode == 2)
{
GameMode = 1;
}
}


}

void DoMove()
{
PlayerRect.y += PlayerYvel;
if((PlayerRect.y + 32 > 1600) || (PlayerRect.y  < 15) || (CheckTileCol(map) ) || HasAiCol())
{
PlayerRect.y -= PlayerYvel;
}



PlayerRect.x += PlayerXvel;
if((PlayerRect.x + 32 > 1600) || (PlayerRect.x < 15) || (CheckTileCol(map) ) || HasAiCol())
{
PlayerRect.x -= PlayerXvel;
}


//Above
AiCol[0].x = PlayerRect.x;
AiCol[0].y = PlayerRect.y + 32;
AiCol[0].w = 32;
AiCol[0].h = 32;

//below
AiCol[1].x = PlayerRect.x;
AiCol[1].y = PlayerRect.y - 32;
AiCol[1].w = 32;
AiCol[1].h = 32;

//Left
AiCol[2].x = PlayerRect.x - 32;
AiCol[2].y = PlayerRect.y;
AiCol[2].w = 32;
AiCol[2].h = 32;

//Right
AiCol[3].x = PlayerRect.x - 32;
AiCol[3].y = PlayerRect.y;
AiCol[3].w = 32;
AiCol[3].h = 32;
}

void DoDraw()
{
if(PlayerYvel < 0)
{
faceing = UP;
PlayerFrame++;
}

else if(PlayerYvel > 0)
{
faceing = DOWN;
PlayerFrame++;
}

else if(PlayerXvel > 0)
{
faceing = RIGHT;
PlayerFrame++;
}
else if(PlayerXvel < 0)
{
faceing = LEFT;
PlayerFrame++;
}
else
{
PlayerFrame = 0;
}

if(PlayerFrame > 1)
{
PlayerFrame = 0;
}

if(faceing == UP)
{
apply_surface(PlayerRect.x - Camera.x,PlayerRect.y - Camera.y,sabrina,screen,&SabrinaClipUp[PlayerFrame]);

}

else if(faceing == DOWN)
{
apply_surface(PlayerRect.x - Camera.x,PlayerRect.y - Camera.y,sabrina,screen,&SabrinaClipDown[PlayerFrame]);
}

else if(faceing == LEFT)
{
apply_surface(PlayerRect.x - Camera.x,PlayerRect.y - Camera.y,sabrina,screen,&SabrinaClipLeft[PlayerFrame]);
}

else if(faceing == RIGHT)
{
apply_surface(PlayerRect.x - Camera.x,PlayerRect.y - Camera.y,sabrina,screen,&SabrinaClipRight[PlayerFrame]);
}
SDL_Delay(70);

}

void DoCameraUpdate()
{
Camera.x = (PlayerRect.x + 32 / 2 ) - 640 / 2; 
Camera.y = (PlayerRect.y + 32 / 2 ) - 480 / 2;

if( Camera.x < 0 )
    {
        Camera.x = 0;
    }
    if( Camera.y < 0 )
    {
        Camera.y = 0;
    }
    if( Camera.x > 1600 - Camera.w )
    {
        Camera.x = 1600 - Camera.w;
    }
    if( Camera.y > 1600 - Camera.h )
    {
        Camera.y = 1600 - Camera.h;
    }

}

void DoAiMove()
{
int a;

for(a=0;a < 10;a++)
{
AiRect[a].x = 50 + rand()%550;
AiRect[a].y = 50 + rand()%550;
AiRect[a].w = 32;
AiRect[a].h = 32;
}

}

void DoAiDraw()
{
int b;
for(b=0;b < 10;b++)
{
apply_surface(AiRect[b].x - Camera.x,AiRect[b].y - Camera.y,sabrina,screen,&SabrinaClipUp[0]);
}
}

void SetupTextOverlay()
{
font = TTF_OpenFont( "sd:/apps/SDL/base 02.ttf", 16 );
}

void DrawTextOverlay(int x,int y,const char *msg,SDL_Color col)
{
text = TTF_RenderText_Solid( font, msg, col);
apply_surface(x,y,text,screen,NULL);
}

void DrawMenuOverlay(int x,int y,char msg,SDL_Color col)
{
text = TTF_RenderText_Solid( font, msg, col);
apply_surface(x,y,text,screen,NULL);
}

void DoMenuInput()
{
if(pressed & WPAD_BUTTON_B)
{
GameMode = 1;
}

else if(pressed & WPAD_BUTTON_UP)
{
if(MenuItemSelected == 0)
{
MenuItemSelected = MenuMax;
}
else
{
MenuItemSelected--;
}

}

else if(pressed & WPAD_BUTTON_DOWN)
{
if(MenuItemSelected == MenuMax)
{
MenuItemSelected = 0;
}
else
{
MenuItemSelected++;
}

}

}

void DrawMenuItems()
{
int d;
int menucorner = 50;
for(d=0;d < 4;d++)
{
DrawMenuOverlay(52,menucorner + d,MenuItemsTable[d],NotSelected);
}
}

void UpdateSelected()
{
DrawMenuOverlay(52,50 + MenuItemSelected,MenuItemsTable[MenuItemSelected],Selected);
}