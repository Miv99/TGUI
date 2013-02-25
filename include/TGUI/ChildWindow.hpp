/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus's Graphical User Interface
// Copyright (C) 2012 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TGUI_CHILD_WINDOW_HPP
#define TGUI_CHILD_WINDOW_HPP

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Movable Panel with title bar.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API ChildWindow : public GroupObject, public ObjectBorders
    {
      public:

        typedef SharedObjectPtr<ChildWindow> Ptr;


        /// Title alignments, possible options for the setTitleAlignment function
        enum TitleAlignment
        {
            /// Places the title on the left side of the title bar
            TitleAlignmentLeft,

            /// Places the title in the middle of the title bar
            TitleAlignmentCentered,

            /// Places the title on the right side of the title bar
            TitleAlignmentRight
        };


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ChildWindow();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Copy constructor
        ///
        /// \param copy  Instance to copy
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ChildWindow(const ChildWindow& copy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Destructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ~ChildWindow();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Overload of assignment operator
        ///
        /// \param right  Instance to assign
        ///
        /// \return Reference to itself
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ChildWindow& operator= (const ChildWindow& right);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the object by calling the copy constructor.
        // This function calls new and if you use this function then you are responsible for calling delete.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ChildWindow* clone();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Creates the child window.
        ///
        /// \param width            Sets the width of the child window.
        /// \param height           Sets the height of the child window.
        /// \param backgroundColor  Sets the background color of the child window.
        /// \param pathname         The path to the folder that contains the images for the titlebar and an optional background image.
        ///                         The folder must also contain an info.txt file, which will give more information about the child window.
        ///
        /// The width and height are the size of the child window, without the title bar nor the borders.
        ///
        /// \return
        ///        - true on success
        ///        - false when the pathname was empty
        ///        - false when the info.txt file was not found
        ///        - false when the images couldn't be loaded
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool load(const std::string& pathname, float width, float height, const sf::Color& backgroundColor = sf::Color::White);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the size of the child window.
        ///
        /// \param width   Sets the new width of the child window
        /// \param height  Sets the new height of the child window
        ///
        /// The width and height are the size of the child window, without the title bar nor the borders.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setSize(float width, float height);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the size of the panel.
        ///
        /// \return Size of the panel
        ///
        /// The size returned by this function is the size of the child window, without the title bar nor the borders.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Vector2f getSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the pathname that was used to load the child window.
        ///
        /// \return Pathname used to load the child window.
        ///         When the child window has not been loaded yet then this function will return an empty string.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual std::string getLoadedPathname() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the background texture of the child window.
        ///
        /// \param texture  Pointer to the texture that should be used as background of the child window
        ///
        /// \warning You should make sure that the texture stays alive.
        ///
        /// If the texture has a different size than the child window then it will be scaled to fill the whole window.
        /// Pass NULL to this function to remove the background texture.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setBackgroundTexture(sf::Texture *const texture = NULL);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the background texture of the child window.
        ///
        /// \return Pointer to the texture that is being used as background of the child window.
        ///         This pointer is NULL when no background texture was set.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual sf::Texture* getBackgroundTexture();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Change the height of the title bar.
        ///
        /// \param height  New height of the title bar
        ///
        /// The default height is the height of the title bar image that is loaded with the load function.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setTitlebarHeight(unsigned int height);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the height of the title bar.
        ///
        /// \return Height of the title bar
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual unsigned int getTitleBarHeight() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the background color of the child window.
        ///
        /// \param backgroundColor  New background color
        ///
        /// The background is fully transparent by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setBackgroundColor(const sf::Color& backgroundColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the background color of the panel.
        ///
        /// The background is fully transparent by default.
        ///
        /// \return The current background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual const sf::Color& getBackgroundColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the transparency of the window.
        ///
        /// \param transparency  The transparency of the window.
        ///                      0 is completely transparent, while 255 means fully opaque.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setTransparency(unsigned char transparency);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the transparency of the window.
        ///
        /// \return The transparency of the window.
        ///         0 is completely transparent, while 255 means fully opaque.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual unsigned char getTransparency() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the title that is displayed in the title bar of the child window.
        ///
        /// \param title  New title for the child window
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setTitle(const sf::String& title);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the title that is displayed in the title bar of the child window.
        ///
        /// \return Title of the child window
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual const sf::String& getTitle() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Set the border color.
        ///
        /// \param borderColor  The color of the borders
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setBorderColor(const sf::Color& borderColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the borde color.
        ///
        /// \return The color of the borders
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual const sf::Color& getBorderColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the size of the borders.
        ///
        /// \param leftBorder    The width of the left border
        /// \param topBorder     The height of the top border
        /// \param rightBorder   The width of the right border
        /// \param bottomBorder  The height of the bottom border
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setBorders(unsigned int leftBorder   = 0,
                                unsigned int topBorder    = 0,
                                unsigned int rightBorder  = 0,
                                unsigned int bottomBorder = 0);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the distance between the title and the side of the title bar.
        ///
        /// \param distanceToSide  distance between the title and the side of the title bar
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setDistanceToSide(unsigned int distanceToSide);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the distance between the title and the side of the title bar.
        ///
        /// \return distance between the title and the side of the title bar
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual unsigned int getDistanceToSide() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the title alignment.
        ///
        /// \param alignment  How should the title be aligned in the title bar?
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setTitleAlignment(TitleAlignment alignment);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the title alignment.
        ///
        /// \return How the title is aligned in the title bar
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual TitleAlignment getTitleAlignment() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Destroys the window.
        ///
        /// When no callback is requested when closing the window, this function will be called automatically.
        ///
        /// When you requested a callback then you get the opportunity to cancel the closure of the window.
        /// If you want to keep it open then don't do anything, if you want to close it then just call this function.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void destroy();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Used internally to get the size of the child window.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Vector2f getDisplaySize();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Used to communicate with EventManager.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool mouseOnObject(float x, float y);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // This function is called when the object is added to a group.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void initialize(tgui::Group *const group);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Send the event to all underlying objects.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void handleEvent(sf::Event& event, float mouseX = 0, float mouseY = 0);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Because this class is derived from sf::Drawable, you can just call the draw function from your sf::RenderTarget.
        // This function will be called and it will draw the child window on the render target.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      public:

        enum ChildWindowCallbacks
        {
            Closed = ObjectCallbacksCount * 1,
            Moved = ObjectCallbacksCount * 2,
//            Resized = ObjectCallbacksCount * 4,
            AllChildWindowCallbacks = ObjectCallbacksCount * 8 - 1,
            ChildWindowCallbacksCount = ObjectCallbacksCount * 8
        };


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        Vector2f       m_Size;
        sf::Color      m_BackgroundColor;
        sf::Texture*   m_Texture;
        sf::Sprite     m_Sprite;

        sf::Text       m_TitleText;
        unsigned int   m_TitleBarHeight;
        std::string    m_LoadedPathname;
        bool           m_SplitImage;
        Vector2f       m_DraggingPosition;
        unsigned char  m_Opacity;
        unsigned int   m_DistanceToSide;
        TitleAlignment m_TitleAlignment;
        sf::Color      m_BorderColor;

        sf::Texture*   m_TextureTitleBar_L;
        sf::Texture*   m_TextureTitleBar_M;
        sf::Texture*   m_TextureTitleBar_R;

        sf::Sprite     m_SpriteTitleBar_L;
        sf::Sprite     m_SpriteTitleBar_M;
        sf::Sprite     m_SpriteTitleBar_R;

        tgui::Button*  m_CloseButton;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_CHILD_WINDOW_HPP
