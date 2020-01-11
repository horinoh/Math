// Math.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//!< “¯ŠK‘w‚Églm(https://github.com/g-truc/glm)‚ª•K—v (Need glm(https://github.com/g-truc/glm) on same hierarchy)
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

//!< glm, DirectXMath‚ÌŒŸØ—p (Verify glm and DirectXMath)
int main()
{
#ifdef USE_GLM
#pragma region GLM
	const auto gA3 = glm::vec3(1.0f, 2.0f, 3.0f);
	const auto gB3 = glm::vec3(3.0f, 7.0f, 1.0f);
	std::cout << gA3 + gB3 << std::endl;

	const auto gA44 = glm::mat4(1.0f);
	std::cout << gA44 << std::endl;
#pragma endregion //!< GLM
#endif //!< USE_GLM

#pragma region DXMATH
	const auto dA3 = DirectX::XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
	const auto dB3 = DirectX::XMVectorSet(3.0f, 7.0f, 1.0f, 0.0f);
	std::cout << DirectX::XMVectorAdd(dA3, dB3) << std::endl;

	const auto dA44 = DirectX::XMMatrixIdentity();
	std::cout << dA44 << std::endl;
#pragma endregion //!< DXMATH

    //std::cout << "Hello World!\n";
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
