#include <chrono>
#include <iostream>

using namespace std;
using Clock = chrono::steady_clock;

#include "DOD.h"
#include "OOD.h"

int main() {
  const int ENTITY_COUNT = 50000;
  const int TEST_COUNT = 16;

  float sum = 0;
  Clock::duration timeOOD, timeDOD;

  for (int i = 0; i < TEST_COUNT; i++) {
    // OOD Test
    {
      list<OOD::GameObject::Ptr> gameObjects;
      for (int i = 0; i < ENTITY_COUNT; i++) {
        OOD::GameObject::Ptr go(new OOD::GameObject());
        go->addComponent<OOD::Transform>();
        gameObjects.push_back(go);
      }

      Clock::time_point start = Clock::now();
      for (auto iter = gameObjects.begin(); iter != gameObjects.end(); ++iter) {
        (*iter)->tick(0.1f);
      }
      timeOOD = Clock::now() - start;
    }

    // DOD Test
    {
      DOD::World world(ENTITY_COUNT);
      Clock::time_point start = Clock::now();
      world.tick(0.1f);
      timeDOD = Clock::now() - start;
    }

    float t1 = chrono::duration_cast<chrono::duration<float> >(timeOOD).count();
    float t2 = chrono::duration_cast<chrono::duration<float> >(timeDOD).count();
    float r = t1 / t2;
    sum += r;

    cout << "OOD Time = " << timeOOD.count()
         << ", DOD time = " << timeDOD.count() << ", OOD/DOD = " << r << endl;
  }

  cout << "Average = " << sum / TEST_COUNT << endl 
	  << "Press Enter...";

  getchar();

}
