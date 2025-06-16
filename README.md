<h1 align="center">🏠 ESP8266 Home Automation System</h1>

<p align="center">
  <b>Control 4 devices using IR Remote, Web Interface, or Manual Buttons</b><br>
  <i>Built with ESP8266 NodeMCU + IR Sensor + HTML UI</i>
</p>

<hr>

<h2>✨ Features</h2>

<ul>
  <li>✅ Control appliances via <b>Wi-Fi Web Interface</b></li>
  <li>✅ Use <b>IR Remote</b> (NEC protocol) for remote control</li>
  <li>✅ Toggle appliances manually with <b>push buttons</b></li>
  <li>✅ <b>Real-time status</b> feedback on Serial Monitor</li>
  <li>✅ Fully <b>responsive HTML UI</b> hosted on ESP8266</li>
  <li>✅ Works without Internet — uses <b>Access Point mode</b></li>
</ul>

<h2>🔧 Hardware Required</h2>

<table>
  <tr><th>Component</th><th>Quantity</th></tr>
  <tr><td>ESP8266 NodeMCU</td><td>1</td></tr>
  <tr><td>IR Receiver (TSOP1838)</td><td>1</td></tr>
  <tr><td>NEC IR Remote</td><td>1</td></tr>
  <tr><td>Push Buttons</td><td>4</td></tr>
  <tr><td>LEDs</td><td>4</td></tr>
  <tr><td>Resistors (220Ω)</td><td>4</td></tr>
  <tr><td>Breadboard + Jumper Wires</td><td>As needed</td></tr>
</table>

<h2>📡 Pin Connections</h2>

<table>
  <tr><th>Device</th><th>ESP8266 Pin</th></tr>
  <tr><td>IR Receiver</td><td>D0</td></tr>
  <tr><td>Button 1</td><td>D4</td></tr>
  <tr><td>Button 2</td><td>D3</td></tr>
  <tr><td>Button 3</td><td>D2</td></tr>
  <tr><td>Button 4</td><td>D1</td></tr>
  <tr><td>LED 1</td><td>D8</td></tr>
  <tr><td>LED 2</td><td>D7</td></tr>
  <tr><td>LED 3</td><td>D6</td></tr>
  <tr><td>LED 4</td><td>D5</td></tr>
</table>

<h2>🌐 Web Interface</h2>

<p>
The ESP8266 hosts a beautiful HTML page with 4 device control buttons.<br>
Access it via browser at: <code>http://192.168.4.1</code> (when connected to AP).
</p>

<img src="images/web-ui-preview.png" width="500"/>

<h2>🛰️ IR Remote Commands</h2>

<p>Use NEC remote codes. Example values (can be replaced as needed):</p>

<ul>
  <li>🔘 LED1: <code>33444015</code></li>
  <li>🔘 LED2: <code>33478695</code></li>
  <li>🔘 LED3: <code>33486855</code></li>
  <li>🔘 LED4: <code>33435855</code></li>
</ul>

<h2>📦 Setup Instructions</h2>

<ol>
  <li>Install Arduino IDE and add ESP8266 board support</li>
  <li>Install required libraries: <code>IRremote</code>, <code>ESP8266WiFi</code>, <code>ESP8266mDNS</code></li>
  <li>Open <code>main.ino</code> and upload the code</li>
  <li>Connect to Wi-Fi AP: <code>node</code> (password: <code>12345678</code>)</li>
  <li>Visit <code>192.168.4.1</code> in browser to control devices</li>
</ol>

<h2>🎥 Demo Video</h2>

<p><i>https://youtu.be/Rg8NLRh2i7I?si=EGKjD8u0etyWJIhx</p>



📬 Author: Jitendra Sharma 📧 Email: jitendrasharma7409@gmail.com 🔗 Follow for more: https://github.com/jitendrasharma-eng?tab=repositories | www.youtube.com/@ECodeLab-mv4jm | linkedin.com/in/jitendra-sharma-484072248 [https://www.linkedin.com/in/jitendra-sharma-484072248?lipi=urn%3Ali%3Apage%3Ad_flagship3_profile_view_base_contact_details%3BdRzhEpUKQSqQh6%2Fm6UayRw%3D%3D]

<p align="center"><b>Happy Home Automation 💡</b></p>
