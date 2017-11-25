#include "PhysicsEngine.h"

static PhysicsEngine* physicsEngine = new PhysicsEngine();

PhysicsEngine::PhysicsEngine()
  : m_RefreshRate(1.f)
  , m_Gravity(9.f)
{
}

PhysicsEngine::~PhysicsEngine()
{
}

void PhysicsEngine::registerPhysicsObject(PhysicsObject* physObj)
{
  m_PhysicsObjects.push_back(physObj);
}

void PhysicsEngine::deregisterPhysicsObject(PhysicsObject* physObj)
{
  PhysicsObjectList_t::iterator findIter = std::find(
	  m_PhysicsObjects.begin(), m_PhysicsObjects.end(), physObj);
  if( findIter != m_PhysicsObjects.end())
  {
    m_PhysicsObjects.erase(findIter);
  }
}

void PhysicsEngine::update(float dTime)
{
  _updatePhysicsObjects(dTime);
}

void PhysicsEngine::_calculatePhysics()
{
  Forces2d_t forces =
    {
      m_Gravity,
      {0, 0},
      {0, 0}
    };
  
  for (auto physObj : m_PhysicsObjects)
  {
    physObj->applyForces(forces);
  }
}

void PhysicsEngine::_updatePhysicsObjects(float dTime)
{
  for (auto physObj : m_PhysicsObjects)
  {
    physObj->update();
  }
}

PhysicsObject::PhysicsObject(Vect2_t position, float mass)
  : m_Position(position)
  , m_Velocity({0, 0})
  , m_Mass(mass)
{
}

PhysicsObject::~PhysicsObject()
{
}

Particle::Particle(Vect2_t  position, float mass,  SDL_Color colour)
  : PhysicsObject(position, mass)
  , m_Colour(colour)
{
  physicsEngine->registerPhysicsObject(this);
}

Particle::~Particle()
{
  physicsEngine->deregisterPhysicsObject(this);
}

Vect2_t Particle::getPosition() const
{
  return m_Position;
}

float Particle::getMass() const
{
  return m_Mass;
}

SDL_Color Particle::getColour() const
{
  return m_Colour;
}

void Particle::applyForces(Forces2d_t forces)
{
  m_Velocity.y -= (forces.gravity * m_Mass);

  m_Velocity += forces.wind;
}

void Particle::update()
{
  m_Position += m_Velocity;
}
