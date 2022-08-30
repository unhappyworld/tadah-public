/* Copyright 2003-2005 ROBLOX Corporation, All Rights Reserved */

#ifndef _70F7A2EE1B6E4dd0AF07E4BFA609A3D1
#define _70F7A2EE1B6E4dd0AF07E4BFA609A3D1

#include "Graphics3D/Vector2.h"
#include "Graphics3D/Vector3.h"
#include "Graphics3D/Vector4.h"
#include "Graphics3D/Matrix3.h"
#include "Graphics3D/Matrix4.h"
#include "Graphics3D/Vector3int16.h"
#include "Graphics3D/Vector2int16.h"
#include "Graphics3D/Color4uint8.h"
#include "Graphics3D/Color3uint8.h"
#include "Graphics3D/CoordinateFrame.h"
#include "Graphics3D/Plane.h"
#include "Graphics3D/Line.h"
#include "Graphics3D/LineSegment.h"

#include "Graphics3D/AABox.h"
#include "Graphics3D/Box.h"
#include "Graphics3D/RBX/RbxCamera.h"
#include "Graphics3D/Color3.h"
#include "Graphics3D/Color4.h"
#include "Graphics3D/g3dmath.h"
#include "Graphics3D/Rect2D.h"
#include "Graphics3D/Sphere.h"

#include "Graphics3D/vectorMath.h"
#include "Graphics3D/Debug.h"

// TODO: this can cause namespace collisions:
//using G3D::Array;

namespace RBX {
	typedef G3D::Vector2 Vector2;
	typedef G3D::Vector3 Vector3;
	typedef G3D::Vector4 Vector4;
	typedef G3D::Vector2int16 Vector2int16;
	typedef G3D::Vector3int16 Vector3int16;
	typedef G3D::Color4uint8 Color4uint8;
	typedef G3D::Color3uint8 Color3uint8;
	typedef G3D::Matrix3 Matrix3;
	typedef G3D::Matrix4 Matrix4;
	typedef G3D::CoordinateFrame CoordinateFrame;
	typedef RBX::RbxRay Ray;
	typedef G3D::Plane Plane;
	typedef G3D::Line Line;
	typedef G3D::LineSegment LineSegment;
	typedef G3D::Color3 Color3;
	typedef G3D::Color4 Color4;
	typedef G3D::Rect2D Rect2D;
	typedef G3D::Box Box;
	typedef G3D::AABox AABox;
	typedef G3D::Sphere Sphere;

	enum IntersectResult
	{
		irNone = 0,
		irPartial =1,
		irFull = 2
	};
}

namespace G3D
{
	std::size_t hash_value(const G3D::Vector3& v);
	std::size_t hash_value(const G3D::Vector3int16& v);
}

#endif