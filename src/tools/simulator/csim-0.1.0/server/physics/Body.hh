/*
 *  Gazebo - Outdoor Multi-Robot Simulator
 *  Copyright (C) 2003
 *     Nate Koenig & Andrew Howard
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
/* Desc: Body class
 * Author: Nate Koenig
 * Date: 13 Feb 2006
 * SVN: $Id: Body.hh 8471 2009-12-17 02:53:42Z natepak $
 *
 * Modified by: Eurico Pedrosa <efp@ua.p>
 * Date: 10 Fev 2010
 *
 * Modification Notes
 *
 *  The modifications presented by me, have the purpose of
 *  removing the 'rendering' and 'gui' modules from the code base.
 *  The reasons behind this decision are simple, allow gazebo to run
 *  on computers with less gpu capabilities and lessen the the coupling
 *  between simulation and visualization.
 *
 */

#ifndef BODY_HH
#define BODY_HH

#include <map>
#include <vector>

#include "Entity.hh"
#include "Pose3d.hh"
#include "Param.hh"
#include "Mass.hh"

namespace gazebo
{
  class Model;
  class Geom;
  class Sensor;
  class XMLConfigNode;
  class PhysicsEngine;

  /// \addtogroup gazebo_physics
  /// \brief The body class
  /// \{

  /// Body class
  class Body : public Entity
  {
    /// \brief Constructor
    public: Body(Entity *parent);

    /// \brief Destructor
    public: virtual ~Body();

    /// \brief Load the body based on an XMLConfig node
    /// \param node XMLConfigNode pointer
    public: virtual void Load(XMLConfigNode *node);

    /// \brief Save the body based on our XMLConfig node
    public: virtual void Save(std::string &prefix, std::ostream &stream);

    /// \brief Initialize the body
    public: virtual void Init();

    /// \brief Finalize the body
    public: void Fini();

    /// \brief Update the body
    public: virtual void Update();

    /// \brief Attach a geom to this body
    /// \param geom Geometery to attach to this body
    public: virtual void AttachGeom( Geom *geom );

    /// \brief Return the velocity of the body
    /// \return Velocity vector
    public: virtual Vector3 GetPositionRate() const = 0;

    /// \brief Return the rotation rates
    /// \return Rotation Rate quaternion
    public: virtual Quatern GetRotationRate() const = 0;

    /// \brief Return the rotation rates
    /// \return Rotation Rate Euler Angles RPY
    public: virtual Vector3 GetEulerRate() const = 0;
    
    /// \brief Set whether this body is enabled
    public: virtual void SetEnabled(bool enable) const = 0;
    
    /// \brief Update the center of mass
    public: virtual void UpdateCoM();

    /// \brief Set whether gravity affects this body
    public: virtual void SetGravityMode(bool mode) = 0;

    /// \brief Set whether this body will collide with others in the model
    public: virtual void SetSelfCollide(bool collide) = 0;

    /// \brief Set the friction mode of the body
    public: void SetFrictionMode( const bool &v );

    /// \brief Set the collide mode of the body
    public: void SetCollideMode( const std::string &m );

    /// \brief Get Self-Collision Flag, if this is true, this body will collide
    //         with other bodies even if they share the same parent.
    public: bool GetSelfCollide();

    /// \brief Set the laser fiducial integer id
    public: void SetLaserFiducialId(int id);

   /// \brief Set the laser retro reflectiveness
    public: void SetLaserRetro(float retro);

    /// \brief Set the linear velocity of the body
    public: virtual void SetLinearVel(const Vector3 &vel) = 0;

    /// \brief Get the linear velocity of the body
    public: virtual Vector3 GetLinearVel() const = 0;

    /// \brief Set the angular velocity of the body
    public: virtual void SetAngularVel(const Vector3 &vel) = 0;

    /// \brief Get the angular velocity of the body
    public: virtual Vector3 GetAngularVel() const = 0;

    /// \brief Set the linear acceleration of the body
    public: void SetLinearAccel(const Vector3 &accel);

    /// \brief Get the linear acceleration of the body
    public: Vector3 GetLinearAccel() const;

    /// \brief Set the angular acceleration of the body
    public: void SetAngularAccel(const Vector3 &accel);

    /// \brief Get the angular acceleration of the body
    public: Vector3 GetAngularAccel() const;

    /// \brief Set the force applied to the body
    public: virtual void SetForce(const Vector3 &force) = 0;

    /// \brief Get the force applied to the body
    public: virtual Vector3 GetForce() const = 0;

    /// \brief Set the torque applied to the body
    public: virtual void SetTorque(const Vector3 &force) = 0;

    /// \brief Get the torque applied to the body
    public: virtual Vector3 GetTorque() const = 0;

    /// \brief Get the vector of all geoms
    public: const std::map<std::string, Geom*> *GetGeoms() const;

    /// \brief Get a geom by name
    public: Geom *GetGeom(const std::string &name) const;

    /// \brief Get the model that this body belongs to
    public: Model *GetModel() const;
    
    /// \brief Get body pigmentation
    public: Vector3 GetPigment() const;

    /// \brief Get the mass of the body
    public: const Mass &GetMass() const { return mass; }

    /// \brief Get the list of interfaces e.g "pioneer2dx_model1::laser::laser_iface0->laser"
    public: void GetInterfaceNames(std::vector<std::string>& list) const;

    /// \brief Get a sensor by name
    public: Sensor *GetSensor( const std::string &name ) const;

    /// Load a new geom helper function
    /// \param node XMLConfigNode used to load the geom
    private: void LoadGeom(XMLConfigNode *node);

    /// Load a new sensor
    /// \param node XMLConfigNode used to load the geom
    private: void LoadSensor(XMLConfigNode *node);

    /// \brief Load a renderable
    private: void LoadVisual(XMLConfigNode *node);

    /// \brief Update the pose of the body
    //protected: void UpdatePose();

    /// \brief Returns list of sensors
    public:  std::vector< Sensor* > &GetSensors();

    /// \brief  Get the size of the body
    public: void GetBoundingBox(Vector3 &min, Vector3 &max) const;

    /// \brief Set the linear damping factor
    public: virtual void SetLinearDamping(double damping) = 0;

    /// \brief Set the angular damping factor
    public: virtual void SetAngularDamping(double damping) = 0;

    public: Entity *GetCoMEntity() { return this->comEntity; }

    /// List of geometries attached to this body
    protected: std::map< std::string, Geom* > geoms;

    /// List of attached sensors
    protected: std::vector< Sensor* > sensors;

    /// Mass properties of the object
    protected: Mass mass;

    protected: bool isStatic;

    /// Used by Model if this body is the canonical body
    ///   model pose = body pose + initModelOffset
    public: Pose3d initModelOffset;

    // Helper entity for separating body pose from center-of-mass pose
    protected: Entity *comEntity;

    /// The pose of the body relative to the model. Can also think of this
    /// as the body's pose offset.
    protected: Pose3d relativePose;

    protected: ParamT<Vector3> *xyzP;
    protected: ParamT<Quatern> *rpyP;
    protected: ParamT<Vector3> *pigmentP;

    protected: ParamT<double> *dampingFactorP;

    protected: PhysicsEngine *physicsEngine;

    protected: ParamT<bool> *turnGravityOffP;
    protected: ParamT<bool> *selfCollideP;

    protected: Vector3 linearAccel;
    protected: Vector3 angularAccel;

    ///  User specified Mass Matrix
    protected: ParamT<bool> *customMassMatrixP;
    protected: ParamT<double> *cxP ;
    protected: ParamT<double> *cyP ;
    protected: ParamT<double> *czP ;
    protected: ParamT<double> *bodyMassP;
    protected: ParamT<double> *ixxP;
    protected: ParamT<double> *iyyP;
    protected: ParamT<double> *izzP;
    protected: ParamT<double> *ixyP;
    protected: ParamT<double> *ixzP;
    protected: ParamT<double> *iyzP;
    protected: Mass customMass;
  };

  /// \}
}

#endif
