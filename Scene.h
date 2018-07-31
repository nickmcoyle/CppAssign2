#pragma once
#include <list>
#include "Layer.h"

namespace Framework
{	
	class Scene
	{
		
	private:		
		using LayerCollection = std::list<Layer>;

	public: 
		typedef LayerCollection::iterator LayerIterator;
		typedef LayerCollection::const_iterator const_LayerIterator;
		LayerIterator begin();
		LayerIterator end();

		Scene();
		Scene(int width, int height);

		Scene(const Scene& other) = default;
		Scene(Scene&& other) = default;

		Scene& operator=(const Scene&) = default;
		Scene& operator=(Scene&&) = default;
		
		void pushBack(Layer const& layer);
		void pushBack(Layer&& layer);
		void remove(Layer const& layer);
			
		void setWidth(int const& width);
		int const& getWidth() const;
		
		void setHeight(int const& height);
		int const& getHeight() const;

	private:
		LayerCollection layers;
		int width;
		int height;
	};
}