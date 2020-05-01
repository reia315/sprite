#pragma once

#include "Vector2.h"
#include "Color.h"
#include "Sprite2D.h"
#include "Texture2D.h"

class Sprite2DShader
	: public Sprite2D::Shader
{
public:

	explicit Sprite2DShader(ID3D11Device* device, ID3D11DeviceContext* deviceContext);

	~Sprite2DShader();

	virtual void begin();

	virtual void end();

	void screen(const Vector2& size);

	void texture(Texture2D& baseMap);

	void texture(Texture2D& baseMap, const Vector2& position, const Vector2& size);

	void translate(const Vector2& position);

	void scale(const Vector2& scale);

	void rotate(float angle);

	void color(const Color& color);

	void center(const Vector2& center);

	Sprite2DShader(const Sprite2DShader& other) = delete;
	Sprite2DShader& operator = (const Sprite2DShader& other) = delete;

private:

	ID3D11Device* m_device{ nullptr };
	ID3D11DeviceContext* m_deviceContext{ nullptr };
	ID3D11Buffer* m_constantBuffer{ nullptr };
	ID3D11VertexShader* m_vertexShader{ nullptr };
	ID3D11PixelShader* m_pixelShader{ nullptr };
	ID3D11InputLayout* m_vertexLayout{ nullptr };
	Texture2D* m_texture{ nullptr };

	struct BufferData
	{
		Vector2 texturePosition{ Vector2::zero };

		Vector2 textureSize{ Vector2::zero };

		Vector2 size{ Vector2::zero };

		Vector2 position{ Vector2::zero };

		Vector2 scale{ Vector2::one };

		float angle{ 0.0f };

		float padding{ 0.0f };

		Color color{ Color::white };

		Vector2 center{ Vector2::zero };

		Vector2 screen{ 640.0f, 480.0f };
	};

	BufferData m_data{};
};