export module null.graphics;

export namespace null
{
	class gfx
	{
	public:
		gfx(const gfx&) = delete;
		enum class api
		{
			vulkan,
			opengl,
			directx,
		};
	};
}