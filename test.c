#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <iostream>

using namespace std;

static void listDir(char *path) {
  DIR *pDir;
  struct dirent *ent;
  int i=0;
  char childpath[512];
  static int cnt = 0;
  pDir = opendir(path);
  memset(childpath, 0, sizeof(childpath));
  while ((ent=readdir(pDir))!= NULL) {
    if (ent->d_type & DT_DIR) {
      if (strcmp(ent->d_name,".") == 0 || strcmp(ent->d_name,"..") == 0) {
        continue;
      }
      sprintf(childpath,"%s/%s",path,ent->d_name);
      printf("path:%s/n", childpath);
      listDir(childpath);
    } else {
      cnt++;
      cout<<cnt<<"hhh"<<ent->d_name<<endl;
      char name[512] = {0};
      char buf[512] = {0};
      int index = 0;
      while (ent->d_name) {
        if (ent->d_name[index] == '.') {
          break;
        }
        name[index] = ent->d_name[index];
        index++;
      }
      sprintf(buf, "bin/adpcm -d -i audio/%s -o out/%s.pcm", ent->d_name, name);
      cout<<buf<<endl;
      system(buf);
    }
  }
}

int main(int argc,char *argv[]) {
  listDir(argv[1]);
  return 0;
}
