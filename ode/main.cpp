#include <iostream>
#include <ode/ode.h>
#define TIME_OVER 30
using namespace std;

int main(int argc,char* args[]){
    dInitODE();
	dWorldID worldID = dWorldCreate();
	dWorldSetGravity(worldID, 0, 0, 1);	
    dBodyID body = dBodyCreate(worldID);
    dBodySetPosition(body, 0, 0, 0);
    float count = 0;
	while(count <= TIME_OVER){
		dWorldStep(worldID, 0.01);
        const dReal* real = dBodyGetPosition(body);
        cout<<"pos:x,y,z:"<<real[0]<<","<<real[1]<<","<<real[2]<<endl;
        const dReal* realvec = dBodyGetLinearVel(body);
        cout<<"vec:x,y,z:"<<realvec[0]<<","<<realvec[1]<<","<<realvec[2]<<endl;

        count += 0.1;
	}
	dWorldDestroy(worldID);
	return 0;
}
