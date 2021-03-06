#pragma once

#include "Data.h"

#include <vector>
#include <cstddef>

EventInfo parseEvent(const uint8_t * input, size_t size);

std::vector<uint8_t> putTracksInOutputFormat(
  const std::vector<Hit>& hits,
  const std::vector<Track>& tracks
);

/*void printSolution(
  const std::vector<Track>& tracks, 
  const std::vector<Hit>& hits,
  std::ostream& stream
);*/ 

double getQuatile(std::vector<double> data, double ratio);

std::vector<std::pair<int, int> > setIntersection(
  const std::vector<std::vector<int> >& eventsDx,
  const std::vector<std::vector<int> >& eventsDy,
  int threshold
);
