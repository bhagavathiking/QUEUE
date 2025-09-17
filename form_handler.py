#!/usr/bin/env python3

import cgi
import html

print("Content-type: text/html\n")

form = cgi.FieldStorage()
name = form.getvalue("username", "Guest")
escaped_name = html.escape(name)

print(f"""
<!DOCTYPE html>
<html>
<head><title>Response</title></head>
<body>
    <h1>Hello, {escaped_name}!</h1>
    <p>This response was generated dynamically using a Python CGI script.</p>
</body>
</html>
""")
