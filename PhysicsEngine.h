#include "GameTypes.h"

#ifndef __PHYSICSENGINE_H__
#define __PHYSICSENGINE_H__

class PhysicsObject
{
 public:  
  virtual void applyForces(Forces2d_t forces) = 0;
  virtual void update() = 0;

  ~PhysicsObject();
  
 protected:
  PhysicsObject(Vect2_t position, float mass);
  
  Vect2_t m_Position;
  Vect2_t m_Velocity;
  float m_Mass;
};

class Particle : protected PhysicsObject
{
 public:
  Particle(Vect2_t position,float mass, SDL_Color colour);
  ~Particle();

  Vect2_t getPosition() const;
  float getMass() const;
  SDL_Color getColour() const;

  void applyForces(Forces2d_t forces) override;

  void update() override;
  
 private:
  SDL_Color m_Colour;
  
};

class PhysicsEngine
{
 public:
  PhysicsEngine();
  virtual ~PhysicsEngine();

  void registerPhysicsObject(PhysicsObject* physObj);

  void deregisterPhysicsObject(PhysicsObject* physObj);

  void update(float dTime);

 private:

  void _calculatePhysics();
  void _updatePhysicsObjects(float dTime);
  
  float m_RefreshRate;
  float m_Gravity;

  typedef std::vector<PhysicsObject*> PhysicsObjectList_t;
  PhysicsObjectList_t m_PhysicsObjects;
};


#endif // __PHYSICSENGINE_H__
