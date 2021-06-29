

struct Map {

  struct MapSize{
    unsigned int xPosition;
    unsigned int yPosition;
  } Size;

  

  // Opera , Reborn possition , End possition
  struct MapInformation {


  } Information;

  // Create NumberList Pointer
  int* Mapp;
  int Map[][];

} Map;




// Create any form map
int Map_Create(unsigned int xPosition,unsigned int yPosition) {
  
  if (xPosition <= 16 || yPosition <= 16) {
    // Size is short
    return 0;
  }
  
  Map.Size.xPosition = xPosition;
  Map.Size.yPosition = yPosition;

  return 1;
}

int Map_Initialization() {

  


  return 1;
}

// Load map to local file
int Map_WriteToFile() {
  FILE* FilePath = NULL;
  // This path unknown
  fopen_s(&FilePath,"","");

  if (FilePath == NULL) {
    return 0;
  }

  // 


  return 1;
}







int main() {



  return 0;
}