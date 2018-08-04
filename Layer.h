#pragma once
#include "Point.h"
#include "VectorGraphic.h"   
#include <list>
#include "PlacedGraphic.h"


	namespace Framework
	{	
		
		class Layer 
		{
		private:			

			typedef std::list<PlacedGraphic> PlacedGraphicCollection;

		public:
			typedef PlacedGraphicCollection::iterator PlacedGraphicIterator;			
			typedef PlacedGraphicCollection::const_iterator const_PlacedGraphicIterator;
			PlacedGraphicIterator begin();
			PlacedGraphicIterator end();

			Layer();
			Layer(const std::string& alias);
			Layer(std::string&& alias);

			Layer(const Layer& other) = default;
			Layer(Layer&& other) = default;

			Layer& operator=(const Layer&) = default;
			Layer& operator=(Layer&&) = default;
			
			void insert(const PlacedGraphic& placedGraphic);
			void insert(PlacedGraphic&& placedGraphic);
			void remove(const PlacedGraphic& placedGraphic);			

			const PlacedGraphicCollection& getPlacedGraphics() const;

			void setAlias(const std::string& alias);
			void setAlias(std::string&& alias);
			const std::string& getAlias() const;			

			bool operator==(const Layer& rhs) const;
			bool operator!=(const Layer& rhs) const;
		
		private:
			PlacedGraphicCollection graphics;
			std::string alias;
			
		};
		
	}

