#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>

struct Transform
{
public:
	Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f))
	{
		this->pos = pos;
		this->rot = rot;
		this->scale = scale;

		this->parent = nullptr;
	}

	inline glm::mat4 GetModel()
	{
		glm::vec3 globalPos = *this->GetGlobalPos();
		glm::mat4 posMat = glm::translate(globalPos);

		glm::vec3 globalScale = *this->GetGlobalScale();
		glm::mat4 scaleMat = glm::scale(globalScale);

		glm::vec3 globalRot = *this->GetGlobalRotEuler();
		glm::mat4 rotX = glm::rotate(globalRot.x, glm::vec3(1.0, 0.0, 0.0));
		glm::mat4 rotY = glm::rotate(globalRot.y, glm::vec3(0.0, 1.0, 0.0));
		glm::mat4 rotZ = glm::rotate(globalRot.z, glm::vec3(0.0, 0.0, 1.0));
		glm::mat4 rotMat = rotX * rotY * rotZ;

		return posMat * rotMat * scaleMat;
	}


	/*
	====================================================================================================
	Position
	====================================================================================================
	*/
	// Getters
	inline glm::vec3* GetLocalPos() 
	{ 
		return &pos; 
	}
	inline glm::vec3* GetGlobalPos()
	{
		if (this->parent != nullptr)
		{
			// Parent's Position
			glm::vec3 globalPos = *parent->GetGlobalPos();

			// Local Position
			glm::vec3 localPos = *this->GetLocalPos();
			glm::vec3 totalPos = globalPos + localPos;

			// Rotated Local Position
			glm::vec3 eulerRotation = *this->GetGlobalRotEuler();

			glm::vec3 eulerRotationX = glm::vec3(eulerRotation.x, 0.0f, 0.0f);
			glm::vec3 eulerRotationY = glm::vec3(0.0f, eulerRotation.y, 0.0f);
			glm::vec3 eulerRotationZ = glm::vec3(0.0f, 0.0f, eulerRotation.z);

			glm::quat quaternionX = glm::quat();
			quaternionX.x = (sin(eulerRotationX.x / 2) * cos(eulerRotationX.y / 2) * cos(eulerRotationX.z / 2)) + (cos(eulerRotationX.x / 2) * sin(eulerRotationX.y / 2) * sin(eulerRotationX.z / 2));
			quaternionX.y = (cos(eulerRotationX.x / 2) * sin(eulerRotationX.y / 2) * cos(eulerRotationX.z / 2)) + (sin(eulerRotationX.x / 2) * cos(eulerRotationX.y / 2) * sin(eulerRotationX.z / 2));
			quaternionX.z = (cos(eulerRotationX.x / 2) * cos(eulerRotationX.y / 2) * sin(eulerRotationX.z / 2)) + (sin(eulerRotationX.x / 2) * sin(eulerRotationX.y / 2) * cos(eulerRotationX.z / 2));
			quaternionX.w = (cos(eulerRotationX.x / 2) * cos(eulerRotationX.y / 2) * cos(eulerRotationX.z / 2)) + (sin(eulerRotationX.x / 2) * sin(eulerRotationX.y / 2) * sin(eulerRotationX.z / 2));
			glm::quat quaternionY = glm::quat();
			quaternionY.x = (sin(eulerRotationY.x / 2) * cos(eulerRotationY.y / 2) * cos(eulerRotationY.z / 2)) + (cos(eulerRotationY.x / 2) * sin(eulerRotationY.y / 2) * sin(eulerRotationY.z / 2));
			quaternionY.y = (cos(eulerRotationY.x / 2) * sin(eulerRotationY.y / 2) * cos(eulerRotationY.z / 2)) + (sin(eulerRotationY.x / 2) * cos(eulerRotationY.y / 2) * sin(eulerRotationY.z / 2));
			quaternionY.z = (cos(eulerRotationY.x / 2) * cos(eulerRotationY.y / 2) * sin(eulerRotationY.z / 2)) + (sin(eulerRotationY.x / 2) * sin(eulerRotationY.y / 2) * cos(eulerRotationY.z / 2));
			quaternionY.w = (cos(eulerRotationY.x / 2) * cos(eulerRotationY.y / 2) * cos(eulerRotationY.z / 2)) + (sin(eulerRotationY.x / 2) * sin(eulerRotationY.y / 2) * sin(eulerRotationY.z / 2));
			glm::quat quaternionZ = glm::quat();
			quaternionZ.x = (sin(eulerRotationZ.x / 2) * cos(eulerRotationZ.y / 2) * cos(eulerRotationZ.z / 2)) + (cos(eulerRotationZ.x / 2) * sin(eulerRotationZ.y / 2) * sin(eulerRotationZ.z / 2));
			quaternionZ.y = (cos(eulerRotationZ.x / 2) * sin(eulerRotationZ.y / 2) * cos(eulerRotationZ.z / 2)) + (sin(eulerRotationZ.x / 2) * cos(eulerRotationZ.y / 2) * sin(eulerRotationZ.z / 2));
			quaternionZ.z = (cos(eulerRotationZ.x / 2) * cos(eulerRotationZ.y / 2) * sin(eulerRotationZ.z / 2)) + (sin(eulerRotationZ.x / 2) * sin(eulerRotationZ.y / 2) * cos(eulerRotationZ.z / 2));
			quaternionZ.w = (cos(eulerRotationZ.x / 2) * cos(eulerRotationZ.y / 2) * cos(eulerRotationZ.z / 2)) + (sin(eulerRotationZ.x / 2) * sin(eulerRotationZ.y / 2) * sin(eulerRotationZ.z / 2));

			glm::vec3* rotatedPos = &(quaternionX * quaternionZ * quaternionY * totalPos);
			return rotatedPos;
		}
		else
		{
			glm::vec3* localPos = GetLocalPos();
			return localPos;
		}
	}
	// Setters
	inline void SetLocalPos(glm::vec3& pos)
	{
		this->pos = pos;
	}
	inline void SetGlobalPos(glm::vec3& pos)
	{
		if (this->parent != nullptr)
		{
			glm::vec3 local = (pos - *parent->GetGlobalPos());
			this->SetLocalPos(local);
		}
		else
		{
			this->SetLocalPos(pos);
		}
	}


	/*
	====================================================================================================
	Rotation
	====================================================================================================
	*/
	// Getters
	inline glm::vec3* GetLocalRotEuler()
	{
		return &rot;
	}
	inline glm::quat* GetLocalRotQuaternion()
	{
		glm::vec3 eulerAngles = *GetLocalRotEuler();

		glm::quat quaternion = glm::quat();
		quaternion.x = (sin(eulerAngles.x / 2) * cos(eulerAngles.y / 2) * cos(eulerAngles.z / 2)) + (cos(eulerAngles.x / 2) * sin(eulerAngles.y / 2) * sin(eulerAngles.z / 2));
		quaternion.y = (cos(eulerAngles.x / 2) * sin(eulerAngles.y / 2) * cos(eulerAngles.z / 2)) + (sin(eulerAngles.x / 2) * cos(eulerAngles.y / 2) * sin(eulerAngles.z / 2));
		quaternion.z = (cos(eulerAngles.x / 2) * cos(eulerAngles.y / 2) * sin(eulerAngles.z / 2)) + (sin(eulerAngles.x / 2) * sin(eulerAngles.y / 2) * cos(eulerAngles.z / 2));
		quaternion.w = (cos(eulerAngles.x / 2) * cos(eulerAngles.y / 2) * cos(eulerAngles.z / 2)) + (sin(eulerAngles.x / 2) * sin(eulerAngles.y / 2) * sin(eulerAngles.z / 2));

		return &quaternion;
	}
	inline glm::vec3* GetGlobalRotEuler()
	{
		if (parent == nullptr)
		{
			return GetLocalRotEuler();
		}
		else
		{
			/*// Parent Rotation
			glm::quat parentQuarternion = *parent->GetGlobalRotQuaternion();
			// Local Rotation
			glm::quat localQuarternion = *this->GetLocalRotQuaternion();
			// Total Rotation
			glm::quat totalQuarternion = parentQuarternion * localQuarternion;
			glm::vec3 totalRot = glm::eulerAngles(totalQuarternion);*/

			glm::vec3 parentRot = *parent->GetGlobalRotEuler();
			glm::vec3 localRot = *this->GetLocalRotEuler();

			glm::vec3 totalRot = parentRot + localRot;
			return &totalRot;
		}
	}
	inline glm::quat* GetGlobalRotQuaternion()
	{
		glm::vec3 eulerAngles = *GetGlobalRotEuler();

		glm::quat quaternion = glm::quat();
		quaternion.x = (sin(eulerAngles.x / 2) * cos(eulerAngles.y / 2) * cos(eulerAngles.z / 2)) + (cos(eulerAngles.x / 2) * sin(eulerAngles.y / 2) * sin(eulerAngles.z / 2));
		quaternion.y = (cos(eulerAngles.x / 2) * sin(eulerAngles.y / 2) * cos(eulerAngles.z / 2)) + (sin(eulerAngles.x / 2) * cos(eulerAngles.y / 2) * sin(eulerAngles.z / 2));
		quaternion.z = (cos(eulerAngles.x / 2) * cos(eulerAngles.y / 2) * sin(eulerAngles.z / 2)) + (sin(eulerAngles.x / 2) * sin(eulerAngles.y / 2) * cos(eulerAngles.z / 2));
		quaternion.w = (cos(eulerAngles.x / 2) * cos(eulerAngles.y / 2) * cos(eulerAngles.z / 2)) + (sin(eulerAngles.x / 2) * sin(eulerAngles.y / 2) * sin(eulerAngles.z / 2));

		return &quaternion;
	}
	// Setters
	inline void SetLocalRot(glm::vec3& rot)
	{
		this->rot = rot;
	}
	inline void SetGlobalRot(glm::vec3& rot)
	{
		if (parent != nullptr)
		{
			glm::vec3 local = (rot - *parent->GetGlobalRotEuler());
			this->SetLocalRot(local);
		}
		else
		{
			this->SetLocalRot(rot);
		}
	}
	

	/*
	====================================================================================================
	Scale
	====================================================================================================
	*/
	// Getters
	inline glm::vec3* GetLocalScale()
	{
		return &scale;
	}
	inline glm::vec3* GetGlobalScale()
	{
		if (parent == nullptr)
		{
			glm::vec3* localScale = GetLocalScale();
			return localScale;
		}
		else
		{
			glm::vec3* globalScale = GetLocalScale();
			glm::vec3* localScale = GetLocalScale();

			glm::vec3 totalScale = (*globalScale * *localScale);
			return &(totalScale);
		}
	}
	// Setters
	inline void SetLocalScale(glm::vec3& scale)
	{
		this->scale = scale;
	}
	inline void SetGlobalScale(glm::vec3& scale)
	{
		if (parent != nullptr)
		{
			glm::vec3 local = (scale - *parent->GetGlobalScale());
			this->SetLocalScale(local);
		}
		else
		{
			this->SetLocalScale(scale);
		}
	}


	/*
	====================================================================================================
	Handling Parenting
	====================================================================================================
	*/
	void SetParent(Transform* newParent)
	{
		glm::vec3 thisGlobalPos = *this->GetGlobalPos();
		//glm::vec3 thisGlobalRot = *this->GetGlobalRotEuler();
		//glm::vec3 thisGlobalScale = *this->GetGlobalScale();

		if (newParent != nullptr)
		{
			// Gameobject is to have a parent so transform values must be based on new parent's global value
			glm::vec3 parentGlobalPos = *newParent->GetGlobalPos();
			//glm::vec3 parentGlobalRot = *newParent->GetGlobalRotEuler();
			//glm::vec3 parentGlobalScale = *newParent->GetGlobalScale();

			thisGlobalPos = thisGlobalPos - parentGlobalPos;
			//thisGlobalRot = parentGlobalRot - thisGlobalRot;
			//thisGlobalScale = parentGlobalScale - thisGlobalScale;

			this->SetLocalPos(thisGlobalPos);
			//this->SetLocalRot(thisGlobalRot);
			//this->SetLocalScale(thisGlobalScale);

			this->parent = newParent;
		}
		else
		{
			// Gameobject is to have no parent so transform values can be global values
			this->SetLocalPos(thisGlobalPos);
			//this->SetLocalRot(thisGlobalRot);
			//this->SetLocalScale(thisGlobalScale);

			this->parent = newParent;
		}
	}

protected:

private:
	Transform* parent;

	// the transform of the object local to it's parent (if no parent the tranform is based against the origin)
	glm::vec3 pos;
	glm::vec3 rot;
	glm::vec3 scale;
};


