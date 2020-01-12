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

		//!< クォータニオン (Quaternion)
		std::cout << "[Quaternion]" << std::endl;

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

		//!< クォータニオン (Quaternion)
		std::cout << "[Quaternion]" << std::endl;

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
	}
#pragma endregion //!< DXMATH
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
