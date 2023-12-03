#include <stdio.h> //I don't like c++ std libs :(
#include <string.h>
#include <stdlib.h>
using namespace std;

typedef struct 
{
    char * Type;
    char * Metadata;
} Token;

class FileAnalyzer
{   
private:
    FILE* ToAnalyse = NULL;
    Token* Tokens = NULL;
    size_t TokensAmount = 0;
    bool Initialized = false;
    bool Analysed = false;

    static int GetFileSize(FILE *File)
    {
        int prev=ftell(File);
        fseek(File, 0L, SEEK_END);
        int sz=ftell(File);
        fseek(File,prev,SEEK_SET); //go back to where we were
        return sz;
    }

    static bool IsNumber(char ToCheck)
    {
        switch (ToCheck)
        {
        case '0': return true;
        case '1': return true;
        case '2': return true;
        case '3': return true;
        case '4': return true;
        case '5': return true;
        case '6': return true;
        case '7': return true;
        case '8': return true;
        case '9': return true;
        default: return false;
        }
    }

public:
    FileAnalyzer(const char * Filename)
    {
        this->ToAnalyse = fopen(Filename, "r");
        this->Initialized = true;
    }

    void Run()
    {
        if (!this->Initialized) return;
        if (this->Analysed) return;
        /* Technically this will be faster */

        int FileSize = FileAnalyzer::GetFileSize(this->ToAnalyse);

        char * Text = (char *) malloc(
            FileSize
        );
        fread //Reading files yey :3
        (
            Text, 
            1,
            FileSize,
            this->ToAnalyse
        );

        Token CurrentTok;
        char Current;
        char* CurrentText = (char *) malloc(0);

        for (int i = 0; i < FileSize; i++)
        {
            Current = Text[i]; 
            
        }

    }
};