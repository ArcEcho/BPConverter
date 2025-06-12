# BPConverter
An attempt to bring Blueprint Nativization back to UE5

## Purpose
+ For educational purposes only
+ To make working with complex Blueprints slightly more manageable

## Important Notes
+ This is an auxiliary tool only - don't expect the converted code to compile directly

## Development Environment
+ Windows 11
+ UE5.5.4

## Usage
+ Convert Blueprints into machine-generated code
+ Use ChatGPT or DeepSeek to refine the output

## Known Issues
+ ~~UDynamicClass has been removed~~
+ Some newer properties are unsupported
+ Additional issues may exist

## Screenshots
1. **Tool Entry Point**  
   ![Tool location in UE editor](ResourcesForReadMe/tool_entry.png)  
   Shows where to find BPConverter in the UE editor interface

2. **Main Tool Interface**  
   ![BPConverter main UI](ResourcesForReadMe/tool_interface.png)  
   The primary conversion interface of BPConverter

3. **Blueprint Example**  
   ![Sample Blueprint for conversion](ResourcesForReadMe/blueprint_example.png)  
   Example of a complex Blueprint ready for conversion

4. **AI Translation Prompt**  
   ![DeepSeek translation prompt](ResourcesForReadMe/deepseek_promts.png)  
   Example prompt for refining code with DeepSeek

5-8. **Conversion Output Examples**  
   ![Generated header file example](ResourcesForReadMe/deepseek_translated_example_header_file.png)  
   ![Generated cpp file example 1](ResourcesForReadMe/deepseek_translated_example_cpp_file_01.png)  
   ![Generated cpp file example 2](ResourcesForReadMe/deepseek_translated_example_cpp_file_02.png)  
   ![Generated cpp file example 3](ResourcesForReadMe/deepseek_translated_example_cpp_file_03.png)  
   Sample outputs after DeepSeek processing, showing header and multiple cpp file sections