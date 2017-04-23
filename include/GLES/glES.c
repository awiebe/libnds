#include <GLES/gl2.h>
#include <nds/arm9/videoGL.h>

typedef struct _gl2_program {
    int32* shader; //all uniform and paramaterless statements(first element is size)
    char** paramName;
    _gl2_command* cmd;
    
}_gl2_program;

struct _gl2 {
    _gl2_program** programs;
    void** shaders;
    _gl2_program* activeProgram
} _gl2;

//Shaders
void glShaderBinary( sizei count, const uint *shaders,
                  enum binaryformat, const void *binary, sizei length );

uint glCreateProgram( void );
void glDeleteProgram( uint program );

void glAttachShader( uint program, uint shader );
void glDetachShader( uint program, uint shader );
void glUseProgram( uint program )
{
    _gl2.activeProgram =&_gl2.programs[program];
    char shader =program.shader;
    
    //imediately modify the program in the graphics engine
    glCallList(shader);
    
}

//Texture

void glGenTextures( sizei n, uint *textures );
void glDeleteTextures( sizei n, uint *textures );
void glBindTexture( enum target, uint texture );

void glTexImage2D( enum target, int level,
                int internalformat, sizei width, sizei height,
                int border, enum format, enum type, void *data );
void glActiveTexture( enum texture )
{
    
}
void glCompressedTexImage2D( enum target, int level,
                          enum internalformat, sizei width, sizei height,
                          int border, sizei imageSize, void *data );

//Wrapping and filtering
void glTexParameter( enum target, enum pname, T param)
{
    
}


//Queries
void glScissor( int left, int bottom, sizei width,
             sizei height );

//blending

void glBlendEquation( enum mode );
void glBlendEquationSeparate( enum modeRGB,
                           enum modeAlpha );

void glBlendFuncSeparate( enum srcRGB, enum dstRGB,
                       enum srcAlpha, enum dstAlpha );
void glBlendFunc( enum src, enum dst );
void glBlendColor( clampf red, clampf green, clampf blue,
                clampf alpha );


//Frame buffer
void glBindFramebuffer( enum target, uint framebuffer );

//back buffers
void glBindRenderbuffer( enum target, uint renderbuffer );
void glDeleteRenderbuffers( sizei n, const
                         uint *renderbuffers );
void glGenRenderbuffers( sizei n, uint *renderbuffers );


void glFinish(void);
void glFlush( void );
