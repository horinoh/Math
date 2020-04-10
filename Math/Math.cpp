// Math.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//!< 再帰的にクローンすること、glmはサブモジュールとして追加してある (Clone recursive, glm is added as submodule)
#define USE_GLM

#ifdef USE_GLM
#pragma region GLM
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#pragma warning(push)
#pragma warning(disable : 4201)
#pragma warning(disable : 4464)
#pragma warning(disable : 4127)
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>
#pragma warning(pop)
static std::ostream& operator<<(std::ostream& rhs, const glm::vec2& Value) { for (auto i = 0; i < Value.length(); ++i) { rhs << Value[i] << ", "; } rhs << std::endl; return rhs; }
static std::ostream& operator<<(std::ostream& rhs, const glm::vec3& Value) { for (auto i = 0; i < Value.length(); ++i) { rhs << Value[i] << ", "; } rhs << std::endl; return rhs; }
static std::ostream& operator<<(std::ostream& rhs, const glm::vec4& Value) { for (auto i = 0; i < Value.length(); ++i) { rhs << Value[i] << ", "; } rhs << std::endl; return rhs; }
static std::ostream& operator<<(std::ostream& rhs, const glm::quat& Value) { for (auto i = 0; i < Value.length(); ++i) { rhs << Value[i] << ", "; } rhs << std::endl; return rhs; }
static std::ostream& operator<<(std::ostream& rhs, const glm::mat2& Value) { for (auto i = 0; i < 2; ++i) { rhs << Value[i]; } rhs << std::endl; return rhs; }
static std::ostream& operator<<(std::ostream& rhs, const glm::mat3& Value) { for (auto i = 0; i < 3; ++i) { rhs << Value[i]; } rhs << std::endl; return rhs; }
static std::ostream& operator<<(std::ostream& rhs, const glm::mat4& Value) { for (auto i = 0; i < 4; ++i) { rhs << Value[i]; } rhs << std::endl; return rhs; }
#pragma endregion //!< GLM
#endif //!< USE_GLM

#pragma region DXMATH
#include <DirectXMath.h>
static std::ostream& operator<<(std::ostream& rhs, const DirectX::XMVECTOR& Value) { for (auto i = 0; i < 4; ++i) { rhs << Value.m128_f32[i] << ", "; } rhs << std::endl; return rhs; }
static std::ostream& operator<<(std::ostream& rhs, const DirectX::XMMATRIX& Value) { for (auto i = 0; i < 4; ++i) { rhs << Value.r[i]; } rhs << std::endl; return rhs; }
#pragma endregion //!< DXMATH

//!< glm, DirectXMathの検証用 (Verify glm and DirectXMath)
int main()
{
#ifdef USE_GLM
#pragma region GLM
	{
		std::cout << "---- glm ----" << std::endl << std::endl;

		//!< ベクタ (Vector)
		std::cout << "[Vector3]" << std::endl;
		const auto A3 = glm::vec3(1.0f, 2.0f, 3.0f);
		const auto B3 = glm::vec3(4.0f, 5.0f, 6.0f);
		std::cout << "A3 = " << A3 << std::endl;
		std::cout << "B3 = " << B3 << std::endl;
		std::cout << "A3 + B3 = " << B3 + A3 << std::endl;
		std::cout << "dot(A3, B3) = " << glm::dot(A3, B3) << std::endl;
		std::cout << "cross(A3, B3) = " << glm::cross(A3, B3) << std::endl;

		//!< マトリクス (Matrix) ... 乗算の順序がDirectXMathとは逆になる(Multiply order is different from DirectXMath)
		//!< 22
		std::cout << "[Matrix22]" << std::endl;
		const auto A22 = glm::mat2(1.0f, -1.0f, -2.0f, 3.0f);
		const auto B22 = glm::mat2(1.0f, 2.0f, 3.0f, 4.0f);
		std::cout << "A22 = " << A22 << std::endl;
		std::cout << "B22 = " << B22 << std::endl;
		std::cout << "A22 * B22 = " << A22 * B22 << std::endl;
		std::cout << "B22 * A22 = " << B22 * A22 << std::endl;
		std::cout << "determinant(A22) = " << glm::determinant(A22) << std::endl;
		const auto InvA22 = glm::inverse(A22);
		std::cout << "inverse(A22) = " << InvA22;
		std::cout << "inverse(A22) * A22 = " << InvA22 * A22;

		//!< 33
		std::cout << "[Matrix33]" << std::endl;
		const auto A33 = glm::mat3(3.0f, -2.0f, 7.0f,
			-5.0f, 1.0f, 4.0f,
			2.0f, -3.0f, -1.0f);
		const auto B33 = glm::mat3(-4.0f, 2.0f, 5.0f, 
			3.0f, -2.0f, 1.0f,
			6.0f, -3.0f, -1.0f);
		std::cout << "A33 = " << A33 << std::endl;
		std::cout << "B33 = " << B33 << std::endl;
		std::cout << "A33 * B33 = " << A33 * B33 << std::endl;
		std::cout << "B33 * A33 = " << B33 * A33 << std::endl;
		const auto C33 = glm::mat3(1.0f, 1.0f, -1.0f,
			-2.0f, -1.0f, 1.0f,
			-1.0f, -2.0f, 1.0f);
		std::cout << "C33 = " << C33 << std::endl;
		std::cout << "determinant(C33) = " << glm::determinant(C33) << std::endl;
		const auto InvC33 = glm::inverse(C33);
		std::cout << "inverse(C33) = " << InvC33;
		std::cout << "inverse(C33) * C33 = " << InvC33 * C33;
		const auto D33 = glm::mat3(2.0f, 4.0f, 6.0f, 
			3.0f, 1.0f, 5.0f, 
			8.0f, 7.0f, 9.0f);
		const auto D3 = glm::vec3(3.0f, 4.0f, 1.0f);
		std::cout << "D33 = " << D33 << std::endl;
		std::cout << "D3 = " << D3 << std::endl;
		//std::cout << "D3 * D33 = " << D3 * D33 << std::endl;
		std::cout << "D33 * D3 = " << D33 * D3 << std::endl;

		//!< クォータニオン (Quaternion)
		const auto Radian = glm::radians(60.0f);
		std::cout << "[Quaternion]" << std::endl;
		//!< quat(w, x, y, z) の順なので注意
		std::cout << "quat identity = " << glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
		float Pitch = glm::radians(30.0f) , Yaw = glm::radians(45.0f), Roll = 0.0f;
		const auto Aq = glm::quat(glm::vec3(Pitch, Yaw, Roll));
		std::cout << "quat(Pitch=" << Pitch << ", Yaw=" << Yaw << ", Roll=" << Roll << ") = Aq = " << Aq;
		std::cout << "conjugate(Aq) = " << glm::conjugate(Aq);
		std::cout << "inverse(Aq) = " << glm::inverse(Aq);
		std::cout << "Aq * inverse(Aq) = " << Aq * glm::inverse(Aq);
		const auto Bq = glm::angleAxis(glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		std::cout << "Bq = angleAxis(radians(45), vec3(0, 1, 0)) = " << Bq;
		std::cout << "angle(Bq) = " << glm::degrees(glm::angle(Bq)) << ", axis(Bq) = " << glm::axis(Bq);
		std::cout << "rotate(Bq, vec3(1, 0, 0)) = " << glm::rotate(Bq, glm::vec3(1.0f, 0.0f, 0.0f));
		//std::cout << "lerp(Aq, Bq, 0.75) = " << glm::lerp(Aq, Bq, 0.5f);
		std::cout << "slerp(Aq, Bq, 0.75) = " << glm::slerp(Aq, Bq, 0.75f);
		std::cout << "mix(Aq, Bq, 0.5) = " << glm::mix(Aq, Bq, 0.75f);
		std::cout << "static_cast<glm::mat4>(Aq) = " << static_cast<glm::mat4>(Aq);
		std::cout << "static_cast<glm::quat>(static_cast<glm::mat4>(Aq));" << static_cast<glm::quat>(static_cast<glm::mat4>(Aq));
		const auto Cq = glm::quat(glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		std::cout << "quat({ 1, 0, 0 }, { 0, 1, 0}) = " << Cq;

		//!< 44
		std::cout << "[Matrix44]" << std::endl;
		std::cout << "identity = " << glm::mat4(1.0f) << std::endl;
		const auto A44 = glm::mat4(1.0f, 0.0f, 1.0f, 2.0f,
			-1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, -1.0f, 0.0f, 1.0f,
			1.0f, 1.0f, -1.0f, -2.0f);
		std::cout << "A44 = " << A44;
		std::cout << "transpose(A44) = " << glm::transpose(A44);
		std::cout << "determinant(A44) = " << glm::determinant(A44) << std::endl;
		const auto InvB44 = glm::inverse(A44);
		std::cout << "inverse(A44) = " << InvB44;
		std::cout << "inverse(A44) * A4 = " << InvB44 * A44;
		const auto B44 = glm::mat4(5.0f, 2.0f, 6.0f, 1.0f,
			0.0f, 6.0f, 2.0f, 0.0f,
			3.0f, 8.0f, 1.0f, 4.0f,
			1.0f, 8.0f, 5.0f, 6.0f);
		const auto C44 = glm::mat4(7.0f, 5.0f, 8.0f, 0.0f,
			1.0f, 8.0f, 2.0f, 6.0f,
			9.0f, 4.0f, 3.0f, 8.0f,
			5.0f, 3.0f, 7.0f, 9.0f);
		std::cout << "B44 = " << B44 << std::endl;
		std::cout << "C44 = " << C44 << std::endl;
		std::cout << "B44 * C44 = " << B44 * C44 << std::endl;
		std::cout << "C44 * B44 = " << C44 * B44 << std::endl;
		const auto D44 = glm::mat4(2.0f, 3.0f, -4.0f, 2.0f,
			4.0f, 1.0f, 4.0f, 5.0f,
			2.0f, 5.0f, 3.0f, 1.0f,
			1.0f, 6.0f, 2.0f, 3.0f);
		const auto D4 = glm::vec4(3.0f, 2.0f, 5.0f, 1.0f);
		std::cout << "D44 = " << D44 << std::endl;
		std::cout << "D4 = " << D4 << std::endl;
		std::cout << "D44 * D4 = " << D44 * D4 << std::endl;

		std::cout << "rotateX = " << glm::rotate(glm::mat4(1.0f), Radian, glm::vec3(1.0f, 0.0f, 0.0f));
		std::cout << "rotateY = " << glm::rotate(glm::mat4(1.0f), Radian, glm::vec3(0.0f, 1.0f, 0.0f));
		std::cout << "rotateZ = " << glm::rotate(glm::mat4(1.0f), Radian, glm::vec3(0.0f, 0.0f, 1.0f));
		std::cout << "rotateAxis({1,1,0}) = " << glm::rotate(glm::mat4(1.0f), Radian, glm::vec3(1.0f, 1.0f, 0.0f));
		
		std::cout << "translate = " << glm::translate(glm::mat4(1.0f), glm::vec3(10.0f, 20.0f, 30.0f));
		std::cout << "scale = " << glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 2.0f, 3.0f));
		//glm::mat4_cast(quat);

		const auto Fovy = 0.16f * glm::pi<float>();
		const auto Aspect = 16.0f / 9.0f;
		const auto Far = 100.0f, Near = 0.001f;
		const auto ProjRH = glm::perspectiveRH(Fovy, Aspect, Near, Far);
		std::cout << "perspectiveRH = " << ProjRH;
		const auto ProjLH = glm::perspectiveLH(Fovy, Aspect, Near, Far);
		std::cout << "perspectiveLH = " << ProjLH;

		const auto CamPos = glm::vec3(0.0f, 0.0f, 5.0f);
		const auto CamTag = glm::vec3(0.0f);
		const auto CamUp = glm::vec3(0.0f, 1.0f, 0.0f);
		/*
		F=Norm(Tag-Pos)
		S=Norm(Cross(F,Up)) [RH]
		U=Cross(S,F) [RH]
		S.x,			U.x,			-F.x[RH],		0,
		S.y,			U.y,			-F.y[RH],		0,
		S.z,			U.z,			-F.z[RH],		0,
		-Dot(S,Pos),	-Dot(U,Pos),	 Dot(F,Pos),	1,
		*/
		const auto ViewRH = glm::lookAtRH(CamPos, CamTag, CamUp);
		std::cout << "lookAtRH = " << ViewRH;
		/*
		F=Norm(Tag-Pos)
		S=Norm(Cross(Up,F)) [LH]
		U=Cross(F,S) [LH]
		S.x,			U.x,			F.x[LH],		0,
		S.y,			U.y,			F.y[LH],		0,
		S.z,			U.z,			F.z[LH],		0,
		-Dot(S,Pos),	-Dot(U,Pos),	-Dot(F,Pos),	1,
		*/
		const auto ViewLH = glm::lookAtLH(CamPos, CamTag, CamUp);
		std::cout << "lookAtLH = " << ViewLH;

		std::cout << "VP(RH)  = " << ViewRH * ProjRH;
		std::cout << "PV(RH)  = " << ProjRH * ViewRH;
		std::cout << "VP(LH)  = " << ViewLH * ProjLH;
		std::cout << "PV(LH)  = " << ProjLH * ViewLH;
	}
#pragma endregion //!< GLM
#endif //!< USE_GLM

#pragma region DXMATH
	{
		std::cout << "---- DirectXMath ----" << std::endl << std::endl;

		//!< ベクタ (Vector)
		std::cout << "[Vector3]" << std::endl;
		const auto A3 = DirectX::XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
		const auto B3 = DirectX::XMVectorSet(4.0f, 5.0f, 6.0f, 0.0f);
		std::cout << "A3 = " << A3 << std::endl;
		std::cout << "B3 = " << B3 << std::endl;
		std::cout << "A3 + B3 = " << DirectX::XMVectorAdd(A3, B3) << std::endl; //!< 加算オペレーターは無い？ (There is no + operator?)
		std::cout << "XMVector3Dot(A3, B) = " << DirectX::XMVector3Dot(A3, B3).m128_f32[0] << std::endl;
		std::cout << "XMVector3Cross(A3, B3) = " << DirectX::XMVector3Cross(A3, B3) << std::endl;

		//!< マトリクス (Matrix) ... 乗算の順序がglmとは逆になる(Multiply order is different from glm)
		//!< 22
		std::cout << "[Matrix22]" << std::endl;
		const auto A22 = DirectX::XMMATRIX(1.0f, -1.0f, 0.0f, 0.0f,
			-2.0f, 3.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f);
		const auto B22 = DirectX::XMMATRIX(1.0f, 2.0f, 0.0f, 0.0f,
			3.0f, 4.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f);
		std::cout << "A22 = " << A22 << std::endl;
		std::cout << "B22 = " << B22 << std::endl;
		std::cout << "A22 * B22 = " << A22 * B22 << std::endl;
		//std::cout << "XMMatrixMultiply(A22, B22) = " << DirectX::XMMatrixMultiply(A22, B22) << std::endl;
		std::cout << "B22 * A22 = " << B22 * A22 << std::endl;
		//!< 行列式、逆行列は4x4版しか用意されてない？ (Is there no determinant and inverse but 4x4?)
		//auto A22Det = DirectX::XMMatrixDeterminant(A22);
		//std::cout << "XMMatrixDeterminant(A22) =" << A22Det.m128_f32[0] << std::endl;
		//const auto InvA22 = DirectX::XMMatrixInverse(&A22Det, A22);
		//std::cout << "XMMatrixInverse(A22) = " << InvA22;
		//std::cout << "A22 * XMMatrixInverse(A22) = " << A22 * InvA22;

		//!< 33
		std::cout << "[Matrix33]" << std::endl;
		const auto A33 = DirectX::XMMATRIX(3.0f, -2.0f, 7.0f, 0.0f,
			-5.0f, 1.0f, 4.0f, 0.0f,
			2.0f, -3.0f, -1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f);
		const auto B33 = DirectX::XMMATRIX(-4.0f, 2.0f, 5.0f, 0.0f,
			3.0f, -2.0f, 1.0f, 0.0f,
			6.0f, -3.0f, -1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f);
		std::cout << "A33 = " << A33 << std::endl;
		std::cout << "B33 = " << B33 << std::endl;
		std::cout << "A33 * B33 = " << A33 * B33 << std::endl;
		std::cout << "B33 * A33 = " << B33 * A33 << std::endl;
		//!< 行列式、逆行列は4x4版しか用意されてない？ (Is there no determinant and inverse but 4x4?)
		//const auto C33 = DirectX::XMMATRIX(1.0f, 1.0f, -1.0f, 0.0f,
		//	-2.0f, -1.0f, 1.0f, 0.0f,
		//	-1.0f, -2.0f, 1.0f, 0.0f,
		//	0.0f, 0.0f, 0.0f, 0.0f);
		//std::cout << "C33 = " << C33 << std::endl;
		//auto C33Det = DirectX::XMMatrixDeterminant(C33);
		//std::cout << "XMMatrixDeterminant(C33) =" << C33Det.m128_f32[0] << std::endl;
		//const auto InvC33 = DirectX::XMMatrixInverse(&C33Det, C33);
		//std::cout << "XMMatrixInverse(C33) = " << InvC33;
		//std::cout << "C33 * XMMatrixInverse(C33) = " << C33 * InvC33;
		const auto D33 = DirectX::XMMATRIX(2.0f, 4.0f, 6.0f, 0.0f,
			3.0f, 1.0f, 5.0f, 0.0f,
			8.0f, 7.0f, 9.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f);
		const auto D3 = DirectX::XMVectorSet(3.0f, 4.0f, 1.0f, 0.0f);
		std::cout << "D33 = " << D33 << std::endl;
		std::cout << "D3 = " << D3 << std::endl;
		std::cout << "XMVector3Transform(D3, D33) = " << DirectX::XMVector3Transform(D3, D33) << std::endl;

		//!< クォータニオン (Quaternion)
		const auto Radian = DirectX::XMConvertToRadians(60.0f);
		std::cout << "[Quaternion]" << std::endl;
		std::cout << "XMQuaternionIdentity = " << DirectX::XMQuaternionIdentity();
		float Pitch = DirectX::XMConvertToRadians(30.0f), Yaw = DirectX::XMConvertToRadians(45.0f), Roll = 0.0f;
		const auto Aq = DirectX::XMQuaternionRotationRollPitchYaw(Pitch, Yaw, Roll); //DirectX::XMQuaternionRotationRollPitchYawFromVector(XMVectorSet(Pitch, Yaw, Roll))もある
		std::cout << "XMQuaternionRotationRollPitchYaw(Pitch=" << Pitch << ", Yaw=" << Yaw << ", Roll=" << Roll << ") = Aq = " << Aq;
		std::cout << "XMQuaternionConjugate(Aq) = " << DirectX::XMQuaternionConjugate(Aq);
		std::cout << "XMQuaternionInverse(Aq) = " << DirectX::XMQuaternionInverse(Aq);
		std::cout << "XMQuaternionMultiply(Aq, XMQuaternionInverse(Aq)) = " << DirectX::XMQuaternionMultiply(Aq, DirectX::XMQuaternionInverse(Aq));
		const auto Bq = DirectX::XMQuaternionRotationAxis(DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f), DirectX::XMConvertToRadians(45.0f)); //XMQuaternionRotationNormalは軸をノーマライズしてくれる
		std::cout << "Bq = XMQuaternionRotationAxis(XMConvertToRadians(45), XMVectorSet(0, 1, 0)) = " << Bq;
		DirectX::XMVECTOR AxisQ;
		float AngleQ;
		DirectX::XMQuaternionToAxisAngle(&AxisQ, &AngleQ, Bq);
		//!< 軸(Vector3)はノーマライズされていないので注意
		std::cout << "XMQuaternionToAxisAngle(Axis, Angle, Bq) -> " << "Angle = " << DirectX::XMConvertToDegrees(AngleQ) << ", Axis = " << DirectX::XMVector3Normalize(AxisQ);
		std::cout << "XMVector3Rotate(XMVectorSet(1, 0, 0), Bq) = " << DirectX::XMVector3Rotate(DirectX::XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f), Bq);
		//std::cout << "XMVectorLerp(Aq, Bq, 0.75) = " << DirectX::XMVectorLerp(Aq, Bq, 0.75f);
		std::cout << "XMQuaternionSlerp(Aq, Bq, 0.75) = " << DirectX::XMQuaternionSlerp(Aq, Bq, 0.75f);
		std::cout << "XMMatrixRotationQuaternion(Aq) = " << DirectX::XMMatrixRotationQuaternion(Aq);
		std::cout << "XMQuaternionRotationMatrix(XMMatrixRotationQuaternion(Aq)) = " << DirectX::XMQuaternionRotationMatrix(DirectX::XMMatrixRotationQuaternion(Aq));
		//!< 2ベクトルからのクォータニオン(ベクトルUをVにするような回転を表すクォータニオン)
		const auto Cq = [](DirectX::XMVECTOR U, DirectX::XMVECTOR V){
			const auto U2V2 = std::sqrt(DirectX::XMVector3Dot(U, U).m128_f32[0] * DirectX::XMVector3Dot(V, V).m128_f32[0]);
			const auto Rp = U2V2 + DirectX::XMVector3Dot(U, V).m128_f32[0];
			//!< U, Vが180度反対方向を向いているような場合
			if (Rp < (std::numeric_limits<float>::epsilon)()* U2V2) {
				const auto Ax = std::abs(U.m128_f32[0]) > std::abs(U.m128_f32[2]) ? DirectX::XMVectorSet(-U.m128_f32[1], U.m128_f32[0], 0.0f, 0.0f) : DirectX::XMVectorSet(0.0f, -U.m128_f32[2], U.m128_f32[1], 0.0f);
				return DirectX::XMQuaternionNormalize(DirectX::XMVectorSet(Ax.m128_f32[0], Ax.m128_f32[1], Ax.m128_f32[2], 0.0f));
			}
			else {
				const auto Ax = DirectX::XMVector3Cross(U, V);
				return DirectX::XMQuaternionNormalize(DirectX::XMVectorSet(Ax.m128_f32[0], Ax.m128_f32[1], Ax.m128_f32[2], Rp));
			}
		}(DirectX::XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f), DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f));
		std::cout << "Quaternion from 2 vector({ 1, 0, 0 }, { 0, 1, 0}) = " << Cq;

		//!< 44
		std::cout << "[Matrix44]" << std::endl;
		std::cout << "XMMatrixIdentity() = " << DirectX::XMMatrixIdentity();
		const auto A44 = DirectX::XMMATRIX(1.0f, 0.0f, 1.0f, 2.0f,
			-1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, -1.0f, 0.0f, 1.0f,
			1.0f, 1.0f, -1.0f, -2.0f);
		std::cout << "A44 = " << A44;
		std::cout << "XMMatrixTranspose(A44) = " << DirectX::XMMatrixTranspose(A44);
		auto A44Det = DirectX::XMMatrixDeterminant(A44);
		std::cout << "XMMatrixDeterminant(A44) = " << A44Det.m128_f32[0] << std::endl;
		const auto InvA44 = DirectX::XMMatrixInverse(&A44Det, A44);
		std::cout << "XMMatrixInverse(A44Det, A44) = " << InvA44;
		std::cout << "A44 * XMMatrixInverse(A44Det, A44) = " << A44 * InvA44;
		const auto B44 = DirectX::XMMATRIX(5.0f, 2.0f, 6.0f, 1.0f,
			0.0f, 6.0f, 2.0f, 0.0f,
			3.0f, 8.0f, 1.0f, 4.0f,
			1.0f, 8.0f, 5.0f, 6.0f);
		const auto C44 = DirectX::XMMATRIX(7.0f, 5.0f, 8.0f, 0.0f,
			1.0f, 8.0f, 2.0f, 6.0f,
			9.0f, 4.0f, 3.0f, 8.0f,
			5.0f, 3.0f, 7.0f, 9.0f);
		std::cout << "B44 = " << B44 << std::endl;
		std::cout << "C44 = " << C44 << std::endl;
		std::cout << "B44 * C44 = " << B44 * C44 << std::endl;
		std::cout << "C44 * B44 = " << C44 * B44 << std::endl;
		const auto D44 = DirectX::XMMATRIX(2.0f, 3.0f, -4.0f, 2.0f,
			4.0f, 1.0f, 4.0f, 5.0f,
			2.0f, 5.0f, 3.0f, 1.0f,
			1.0f, 6.0f, 2.0f, 3.0f);
		const auto D4 = DirectX::XMVectorSet(3.0f, 2.0f, 5.0f, 1.0f);
		std::cout << "D44 = " << D44 << std::endl;
		std::cout << "D4 = " << D4 << std::endl;
		std::cout << "XMVector4Transform(D4, D44) = " << DirectX::XMVector4Transform(D4, D44) << std::endl;

		std::cout << "XMMatrixRotationX = " << DirectX::XMMatrixRotationX(Radian);
		std::cout << "XMMatrixRotationY = " << DirectX::XMMatrixRotationY(Radian);
		std::cout << "XMMatrixRotationZ = " << DirectX::XMMatrixRotationZ(Radian);
		std::cout << "XMMatrixRotationAxis({1,1,0}) = " << DirectX::XMMatrixRotationAxis(DirectX::XMVectorSet(1.0f, 1.0f, 0.0f, 0.0f), Radian);

		std::cout << "XMMatrixTranslationFromVector = " << DirectX::XMMatrixTranslationFromVector(DirectX::XMVectorSet(10.0f, 20.0f, 30.0f, 1.0f));
		std::cout << "XMMatrixScalingFromVector = " << DirectX::XMMatrixScalingFromVector(DirectX::XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f));
		//DirectX::XMMatrixRotationQuaternion();

		const auto Fovy = 0.16f * DirectX::XM_PI;
		const auto Aspect = 16.0f / 9.0f;
		const auto Far = 100.0f, Near = 0.001f;
		const auto ProjRH = DirectX::XMMatrixPerspectiveFovRH(Fovy, Aspect, Near, Far);
		std::cout << "XMMatrixPerspectiveFovRH = " << ProjRH;
		const auto ProjLH = DirectX::XMMatrixPerspectiveFovLH(Fovy, Aspect, Near, Far);
		std::cout << "XMMatrixPerspectiveFovLH = " << ProjLH;

		const auto CamPos = DirectX::XMVectorSet(0.0f, 0.0f, 5.0f, 1.0f);
		const auto CamTag = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
		const auto CamUp = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
		/*
		F = Norm(Pos-Tag) <RH>
		S = Norm(Cross(Up,F))
		U = Cross(F,S)
		Transpose(
		S.x,	S.y,	S.z,	Dot(S,-Pos),
		U.x,	U.y,	U.z,	Dot(U,-Pos),
		F.x,	F.y,	F.z,	Dot(F,-Pos),
		0,		0,		0,		1,
		)
		*/
		const auto ViewRH = DirectX::XMMatrixLookAtRH(CamPos, CamTag, CamUp);
		std::cout << "XMMatrixLookAtRH = " << ViewRH;
		/*
		F = Norm(Tag-Pos) <LH>
		S = Norm(Cross(Up,F))
		U = Cross(F,S)
		Transpose(
		S.x,	S.y,	S.z,	Dot(S,-Pos),
		U.x,	U.y,	U.z,	Dot(U,-Pos),
		F.x,	F.y,	F.z,	Dot(F,-Pos),
		0,		0,		0,		1,
		)
		*/
		const auto ViewLH = DirectX::XMMatrixLookAtLH(CamPos, CamTag, CamUp);
		std::cout << "XMMatrixLookAtLH = " << ViewLH;

		std::cout << "VP(RH)  = " << DirectX::XMMatrixMultiply(ViewRH, ProjRH);
		std::cout << "PV(RH)  = " << DirectX::XMMatrixMultiply(ProjRH, ViewRH);
		std::cout << "VP(LH)  = " << DirectX::XMMatrixMultiply(ViewLH, ProjLH);
		std::cout << "PV(LH)  = " << DirectX::XMMatrixMultiply(ProjLH, ViewLH);
	}
#pragma endregion //!< DXMATH
	/*
	Viewport(GL)
	  W/2,	    0,	      0,	0,
		0,	  H/2,	      0,	0,
		0,	    0,	(F-N)/2,	0,
	X+W/2,	Y+H/2,	(F+N)/2,	1,

	Viewport(VK)
	Clip = https://github.com/LunarG/VulkanSamples/commit/0dd36179880238014512c0637b0ba9f41febe803
	1,  0,   0, 0,
	0, -1,   0, 0,
	0,	0, 1/2, 0,
	0,  0, 1/2, 1,
	Clip * Viewport(GL) = 
	  W/2,	    0,	      0,	0,
		0,	 -H/2,	      0,	0,
		0,	    0,	(F-N)/4,	0,
	X+W/2,	Y+H/2, (3F+N)/4,	1,

	Viewport(DX) ... https://docs.microsoft.com/ja-jp/windows/uwp/graphics-concepts/viewports-and-clipping
	  W/2,	    0,	  0,	0,
		0,	 -H/2,	  0,	0,
		0,	    0,	F-N,	0,
	X+W/2,	Y+H/2,	  N,	1,
	*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
