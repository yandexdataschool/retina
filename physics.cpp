#include "physics.h"
#include <limits>
TrackPure operator*(const TrackPure& one, const double alpha)
{
  return TrackPure(
      one.xOnZ0 * alpha,
      one.yOnZ0 * alpha,
      one.dxOverDz * alpha,
      one.dyOverDz * alpha
  );
}

TrackPure operator+(const TrackPure& one, const TrackPure& other) 
{
  return TrackPure(
    one.xOnZ0 + other.xOnZ0,
    one.yOnZ0 + other.yOnZ0,
    one.dxOverDz + other.dxOverDz,
    one.dyOverDz + other.dyOverDz
  );
}

inline double square(double x)
{
  return x * x;
}

double getDistanceFromTrackToHit(const TrackPure& track, const Hit& hit)
{
  return square(hit.x - track.xOnZ0 - track.dxOverDz * hit.z) +
         square(hit.y - track.yOnZ0 - track.dyOverDz * hit.z);
}

double calculateResponce(const TrackPure& track, const Hit& hit, double sharpness)
{
  return exp(-getDistanceFromTrackToHit(track, hit) * sharpness);
}