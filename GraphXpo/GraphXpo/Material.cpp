#include "Material.h"

Material::Material(std::shared_ptr<SimpleVertexShader> const& vertex, std::shared_ptr<SimplePixelShader> const& pixel, ID3D11ShaderResourceView* diff, ID3D11SamplerState* sampler)
{
	vs = vertex;
	ps = pixel;

	diffuse = diff;
	textureSampler = sampler;
}

Material::Material(std::shared_ptr<SimpleVertexShader> const & vertex, std::shared_ptr<SimplePixelShader> const & pixel, ID3D11ShaderResourceView * diff, ID3D11ShaderResourceView * spec, ID3D11SamplerState * sampler)
{
	vs = vertex;
	ps = pixel;

	diffuse = diff;
	specular = spec;
	textureSampler = sampler;
}

Material::Material(std::shared_ptr<SimpleVertexShader> const & vertex, std::shared_ptr<SimplePixelShader> const & pixel, ID3D11ShaderResourceView * diff, ID3D11ShaderResourceView * spec, ID3D11ShaderResourceView * norm, ID3D11SamplerState * sampler)
{
	vs = vertex;
	ps = pixel;

	diffuse = diff;
	specular = spec;
	normal = norm;
	textureSampler = sampler;
}

Material::~Material()
{
	//release textures + samplers
	diffuse->Release();
	specular->Release();
	normal->Release();
	//textureSampler->Release();
}

std::shared_ptr<SimpleVertexShader> Material::GetVertexShader()
{
	return vs;
}

std::shared_ptr<SimplePixelShader> Material::GetPixelShader()
{
	return ps;
}

ID3D11ShaderResourceView* Material::GetDiffuse()
{
	return diffuse;
}
ID3D11ShaderResourceView * Material::GetSpecular()
{
	return specular;
}
ID3D11ShaderResourceView * Material::GetNormal()
{
	return normal;
}
ID3D11SamplerState* Material::GetSamplerState()
{
	return textureSampler;
}

