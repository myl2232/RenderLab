#ifndef _RTX_RT_MATERIAL_LAMBERTIAN_H_
#define _RTX_RT_MATERIAL_LAMBERTIAN_H_

#include <CppUtil/RTX/Material.h>

#include <glm/vec3.hpp>

namespace RTX {
	class Texture;

	class Lambertian : public Material {
		MATERIAL_SETUP(Lambertian)
	public:
		Lambertian(float r, float g, float b);
		Lambertian(const glm::vec3 & albedo);
		Lambertian(CppUtil::Basic::CPtr<Texture> albedo);

		// 返回值为 true 说明光线继续传播
		// 返回值为 false 说明光线不再传播
		virtual bool Scatter(const HitRecord & rec) const;
		
		const CppUtil::Basic::CPtr<Texture> GetTexture() const { return albedo; }
	protected:
		CppUtil::Basic::CPtr<Texture> albedo;
	};
}

#endif // !_RTX_RT_MATERIAL_LAMBERTIAN_H_
