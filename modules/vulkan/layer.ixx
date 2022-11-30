export module null.vulkan:layer;
export namespace null
{
	struct layer
	{
		layer(const char* layer_name) : name(layer_name) {}
		const char* name;
	};
}