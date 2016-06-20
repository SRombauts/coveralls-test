#pragma once


class obj
{
public:
   obj (void);
   ~obj (void);

   void used() const;

   void unused() const;

   inline int inlineUsed (void) const
   {
      return mValue;
   }

   inline int inlineUnused (void) const
   {
      return mValue;
   }

private:
   int mValue;
};
