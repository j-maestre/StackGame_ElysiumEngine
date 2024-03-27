###### [<- Back](../documentation.md)
## Text Systems

This system is in charge of the management of the rendering of the text on screen. For the operation of this in the constructor we need to pass it the text shaders and the font we want to use.

[Text font resources in .ttf format](https://fonts.google.com/)

Example:
```c++
std::unique_ptr<char> buffer_tex_fs = ReadFile("../assets/text_shader.fs");
std::unique_ptr<char> buffer_tex_vs = ReadFile("../assets/text_shader.vs");

auto maybe_tex_vs = Shader::create(Shader::kType_Vertex, buffer_tex_vs.get(), (unsigned int)strlen(buffer_tex_vs.get()));
auto maybe_tex_fs = Shader::create(Shader::kType_Fragment, buffer_tex_fs.get(), (unsigned int)strlen(buffer_tex_fs.get()));

if (!maybe_tex_fs.has_value() || !maybe_tex_vs.has_value()) { return -1; }

TextSystem tex_sys(maybe_tex_vs.value(), maybe_tex_fs.value(), "../assets/NunitoSans.ttf");
```
Then in the loop of the game you will have to call `apply()` and you need pass the ECS and the Windows.

```c++
tex_sys.apply(ely.ecs, w);
```
> [!CAUTION]  
> You have to put it after the rendering system.