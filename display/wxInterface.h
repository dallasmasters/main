#ifndef WX_DISPLAY_INTERFACE_H
#define WX_DISPLAY_INTERFACE_H

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Declarations / Definitions involving (tying) wxWidgets and migrated code, stripped out of wxWidgtes dependencies
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#if defined (__APPLE__)
    #if defined (Q_FORWARD_DECLARE_OBJC_CLASS)
        #undef Q_FORWARD_DECLARE_OBJC_CLASS
    #endif
    #define Q_FORWARD_DECLARE_OBJC_CLASS( x )
    #include <qdebug.h>
#endif

#include <wx/colourdata.h>



#include "gui/wxGuiInterface.h"

#include "new-gui/brat/DataModels/PlotData/XYPlotData.h"


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//										CBratLookupTable	
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "PlotData/BratLookupTable.h"


//void CPlotColor::Get(wxColour& color) const
//{
//  if (Ok() == false)
//  {
//    return;
//  }
//  uint8_t r;
//  uint8_t g;
//  uint8_t b;
//  uint8_t a;
//  Get(r, g, b, a);
//  color.Set(r,g,b);
//}
//wxColour CPlotColor::GetWXColor() const
//{
//  wxColour color;
//  Get(color);
//  return color;
//}
inline wxColour color_cast( const CPlotColor &c )
{
	wxColour color;
	if ( c.Ok() )
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
		c.Get( r, g, b, a );
		color.Set( r, g, b );
	}
	return color;
}

//void CPlotColor::Set(const wxColour& color)
//{
//  Set(color.Red(), color.Green(), color.Blue());
//}
//CPlotColor::CPlotColor(const wxColour& color)
//{
//  Set(color);
//}
inline CPlotColor color_cast( const wxColour &color )
{
	CPlotColor c;
	c.Set(color.Red(), color.Green(), color.Blue());
	return c;
}


//void CPlotColor::Set(wxColourData& colorData, int32_t indexCustomColor)
//{
//  if (indexCustomColor < 0)
//  {
//    Set(colorData.GetColour());
//  }
//  else
//  {
//    Set(colorData.GetCustomColour(indexCustomColor));
//  }
//}
//const CPlotColor& CPlotColor::operator =(wxColourData& color)
//{
//  Set(color);
//  return *this;
//}
inline CPlotColor color_cast( const wxColourData &colorData, int32_t indexCustomColor = -1 )
{
	if ( indexCustomColor < 0 )
	{
		return color_cast(colorData.GetColour());
	}
	else
	{
		return color_cast(colorData.GetCustomColour( indexCustomColor ) );
	}
}






//////////////////////////////////////////////////////////////////////////////////////////////////////////
//										CXYPlotProperties
//////////////////////////////////////////////////////////////////////////////////////////////////////////





inline void SetColor( CXYPlotProperties &p, const wxColour& color)
{
	p.SetColor( color_cast(color) );
}


inline void SetColor( CXYPlotProperties &p, wxColourData& colorData, int32_t indexCustomColor = -1 )
{
	if ( indexCustomColor < 0 )
	{
		SetColor( p, colorData.GetColour() );
	}
	else
	{
		SetColor( p, colorData.GetCustomColour( indexCustomColor ) );
	}
}



#endif		//WX_DISPLAY_INTERFACE_H
