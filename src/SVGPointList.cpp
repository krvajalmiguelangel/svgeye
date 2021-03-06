//////////////////////////////////////////////////////////////////////////////
// Name:        SVGPointList.cpp
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by genList.py
//////////////////////////////////////////////////////////////////////////////

#include "SVGPointList.h"
#include <wx/tokenzr.h>
#include <wx/arrimpl.cpp>
WX_DEFINE_OBJARRAY(wxSVGPointListBase);

wxString wxSVGPointList::GetValueAsString() const
{
  wxString value;
  for (int i=0; i<(int)GetCount(); i++)
    value += (i==0 ? wxT("") : wxT(" ")) + 
      wxString::Format(wxT("%%f,%%f"), Item(i).GetX(), Item(i).GetY());
  return value;
}

void wxSVGPointList::SetValueAsString(const wxString& value)
{
  int num = 0;
  double numbers[2];
  wxStringTokenizer tkz(value, wxT(", \t"));
  while (tkz.HasMoreTokens()) 
  { 
    wxString token = tkz.GetNextToken(); 
    if (token.length() && token.ToDouble(&numbers[num]))
    {
      num++;
      if (num == 2)
      {
        wxSVGPoint point;
        point.SetX(numbers[0]);
        point.SetY(numbers[1]);
        Add(point);
        num = 0;
      }
    }
  }
}
